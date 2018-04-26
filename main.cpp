#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include <limits.h>
#include "op_table.h"
#include "sym_table.h"
#include "registers.h"

bool isNum(std::string input) {
    if (input[0] != '#')  {
        for (int i = 0; i < input.length(); ++i) {
            if (!isdigit(input[i])) {
                return false;
            }
        }        
    }
    else {
        for (int i = 1; i < input.length(); ++i) {
            if (!isdigit(input[i])) {
                return false;
            }
        }
    }
    return true;
}

std::vector<std::string> parseOperand(std::string operand) {
    std::vector<std::string> currentOperand;
    std::string splitOperand;
    std::stringstream operandStream(operand);

    while (getline(operandStream, splitOperand, ',')) {
        currentOperand.push_back(splitOperand);
    }
    return currentOperand;
}

/*
    Implementation of the first pass algorithm. 
*/
void passOne(std::vector<std::string>& input, std::unique_ptr<OpTable>& opTable, std::unique_ptr<SymTable>& symTable, int& progLength, int& startAddr) {
    std::string currentLabel = input[0];
    std::string currentOpcode = input[1];
    std::string currentOperand = input[2];
    int locCounter = 0;
    int lineIter = 0;

    std::cout << "LOCCTR:" << std::endl;
    if (currentOpcode == "START") {
        locCounter = std::stoi(currentOperand, nullptr, 16);
        startAddr = locCounter;
        // TODO: Write line to intermediate file
        std::cout << std::setfill('0') << std::setw(4) << std::hex << locCounter << std::endl;
        lineIter += 3;
        currentLabel = input[lineIter];
        currentOpcode = input[lineIter + 1];
        currentOperand = input[lineIter + 2];
    }

    while (currentOpcode != "END" && lineIter < input.size()) {

        // Remove X from operand if inderect addressing is used
        if (currentOperand.substr(currentOperand.size() - 2) == ",X") {
            currentOperand = currentOperand.substr(0, currentOperand.size() - 2);
        }

        if (currentLabel != "") {
            if (symTable->insertSymbol(currentLabel, locCounter, currentOperand) == false) {
                throw  std::invalid_argument("Symbol" + currentLabel + " was already in SYMTAB.");
            }
        }

        if (currentOpcode[0] == '+') {
            std::string trimmedOpcode(currentOpcode.substr(1));
            if (opTable->isInOpTable(trimmedOpcode) && opTable->getFormat(trimmedOpcode) == 3) {
                locCounter += 4;
            }
            else {
                throw  std::invalid_argument("Opcode" + trimmedOpcode + " was not in OPTAB, or had a + and wasn't a 3 format instruction.");
            }
        }
        else if (opTable->isInOpTable(currentOpcode)) {
            locCounter += opTable->getFormat(currentOpcode);
        }
        else if (currentOpcode == "WORD") {
            locCounter += 3;  
        }
        else if (currentOpcode == "RESW") {
            locCounter += 3 * std::stoi(currentOperand);
        }
        else if (currentOpcode == "RESB") {
            locCounter += std::stoi(currentOperand);
        }
        else if (currentOpcode == "BYTE") {
            int constLength = 0;
            std::string trimmedOperand = currentOperand;

            trimmedOperand.erase(0, 2);
            trimmedOperand.erase(trimmedOperand.length() - 1, 1);
            if (currentOperand[0] == 'X') {
                for (int i : trimmedOperand) {
                    if (i % 2 == 0) {
                        constLength += 1;  
                    }
                }
            }

            else if (currentOperand[0] == 'C') {
                for (int i : trimmedOperand) {
                    constLength += 1;  
                }
            }
            locCounter += constLength;
        }
        else if (currentOpcode == "BASE") {
            locCounter = locCounter;
        }
        else if (currentOpcode == "LTORG") {
            locCounter = locCounter;
        }
        else if (currentOpcode == "EQU") {
            // TODO: Parse equations
            symTable->insertSymbol(currentLabel, locCounter, currentOperand);
        }
        else {
            throw  std::invalid_argument("OpCode " + currentOpcode + " was not in OPTAB.");
        }

        // TODO: Write line to intermediate file
        std::cout << std::setfill('0') << std::setw(4) << std::hex << locCounter << std::endl;

        lineIter += 3;
        if (lineIter < input.size()) {
	        currentLabel = input[lineIter];
            currentOpcode = input[lineIter + 1];
       	    currentOperand = input[lineIter + 2];
        }
    }

    progLength = locCounter - startAddr;
    std::cout << "Program Length: " << std::setfill('0') << std::setw(4) << std::hex << progLength << std::endl;
}

void passTwo(std::vector<std::string>& input, std::unique_ptr<OpTable>& opTable, std::unique_ptr<SymTable>& symTable, int& progLength, int& startAddr) {
    Registers registers;
    std::string currentLabel = input[0];
    std::string currentOpcode = input[1];
    std::string textRecord = "T";
    std::vector<std::string> currentOperand = parseOperand(input[2]);
    int locCounter = 0;
    int lineIter = 0;

    std::cout << "OBJ CODE:" << std::endl;
    if (currentOpcode == "START") {
        lineIter += 3;
        currentLabel = input[lineIter];
        currentOpcode = input[lineIter + 1];
        currentOperand = parseOperand(input[lineIter + 2]);
    }

    // TODO: Write header line
    std:: cout << "HCOPY" << " " << std::setfill('0') << std::setw(6) << std::hex << progLength;
    std::cout << std::setfill('0') << std::setw(6) << std::hex << startAddr << std::endl;

    while (currentOpcode != "END" && lineIter < input.size()) {
        bool extendedFormat = false;
        std::stringstream outputStream;
        std::string objCode = "";

        if (currentOpcode[0] == '+') {
            currentOpcode = currentOpcode.substr(1);
            extendedFormat = true;
        }

        if (opTable->isInOpTable(currentOpcode)) {
            for (int i = 0; i < currentOperand.size(); ++i) {
                int symbolIndex = symTable->isInSymTable(currentOperand[i]);

                if (symbolIndex != INT_MAX) {
                    currentOperand[i] = std::to_string(symTable->getSymbol(symbolIndex).getLocation());
                }
                else if (!isNum(currentOperand[i]) && !registers.isRegister(currentOperand[i])) {
                    throw  std::invalid_argument("Operand " + currentOperand[i] + " was not a symbol, a register, or a number.");
                }
            }

            // Assemble object code instruction
            if (opTable->getFormat(currentOpcode) == 1) {
                outputStream << std::hex << opTable->getOpcode(currentOpcode);
                objCode = outputStream.str();
            }
            else if (opTable->getFormat(currentOpcode) == 2) {
                outputStream << std::hex << opTable->getOpcode(currentOpcode);
                for (int i = 0; i < currentOperand.size(); ++i) {
                    outputStream << std::to_string(registers.getRegister(currentOperand[i]).getLocation());
                }
                if (currentOperand.size() == 1) {
                    outputStream << "0";
                }
                objCode = outputStream.str();   
            }
            if (opTable->getFormat(currentOpcode) == 3) {
                int opPlusNI = opTable->getOpcode(currentOpcode);

                // n and i bits
                if (currentOperand[0][0] = '@') {
                    opPlusNI += 0x10;
                }
                if (currentOperand[0][0] = '#') {
                    opPlusNI += 0x01;
                    currentOperand[0] = currentOperand[0].substr(1);
                }
                else {
                    opPlusNI += 0x11;
                }
                outputStream << std::hex << opPlusNI;

                // x bit
                if (currentOperand[currentOperand.size() - 1] == "X") {
                    outputStream << "1";
                }
                else {
                    outputStream << "0";
                }

                // b and p bits
                outputStream << "00";

                // e bit
                if (extendedFormat == true) {
                    outputStream << "1";
                }
                else {
                    outputStream << "0";
                }

                // disp/address bits
                outputStream << std::hex << std::stoi(currentOperand[0]);

                objCode = outputStream.str();
            }
        }

        else if (currentOpcode == "WORD" || currentOpcode == "BYTE") {
            // Convert constant to object code
            if (currentOperand[0][0] == 'X') {
                currentOperand[0] = currentOperand[0].substr(2, currentOperand[0].length() - 2);
            }
            if (currentOperand[0][0] == 'C') {
                std::string character = currentOperand[0].substr(2, currentOperand[0].length() - 2);
                for (int i = 0; i < character.length(); ++i) {
                    outputStream << std::hex << int(character[i]);
                }
            }
            else {
                outputStream << std::hex << std::stoi(currentOperand[0]);
            }
            objCode = outputStream.str();

        }

        lineIter += 3;
        if (lineIter < input.size()) {
	        currentLabel = input[lineIter];
            currentOpcode = input[lineIter + 1];
       	    currentOperand = parseOperand(input[lineIter + 2]);
        }
    }

    // TODO: Write last text record
    // TODO: Write end record
}

int main(int argc, char* argv[]) {
    std::vector<std::string> inputVector;

    if (argc <= 1) {
        throw std::invalid_argument("No file was specified.");
    }
    
    else {
        std::string currentLine = "";
        std::string token = "";
        std::ifstream file(argv[1]);

        if (file) {
            while (getline(file, currentLine)) {
                if (currentLine[0] != '.' && currentLine != "") {
                    std::stringstream lineStream(currentLine);

                    while (getline(lineStream, token, '\t')) {
                        if (token[0] != '.') {
                            inputVector.push_back(token);
                        }
                    }
                }
            }

            std::unique_ptr<OpTable> optTable (new OpTable);
            std::unique_ptr<SymTable> symTable (new SymTable);
            int progLength = 0;
            int startAddr = 0;
            passOne(inputVector, optTable, symTable, progLength, startAddr);
            passTwo(inputVector, optTable, symTable, progLength, startAddr);
        }

        else {
            throw std::invalid_argument("File was not found.");
        }
    }
}