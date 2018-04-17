#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include "op_table.h"
#include "sym_table.h"

/*
    Implementation of the first pass algorithm. 
*/
void passOne(std::vector<std::string>& input, std::unique_ptr<OpTable>& opTable, std::unique_ptr<SymTable>& symTable) {
    std::string currentLabel = input[0];
    std::string currentOpcode = input[1];
    std::string currentOperand = input[2];
    int locCounter = 0;
    int programLength = 0;
    int startAddress = 0;
    int lineIter = 0;

    std::cout << "LOCCTR:" << std::endl;
    if (currentOpcode == "START") {
        locCounter = std::stoi(currentOperand, nullptr, 16);
        startAddress = locCounter;
        // TODO: Write line to intermediate file
        std::cout << std::setfill('0') << std::setw(4) << std::hex << locCounter << std::endl;
        lineIter += 3;
        currentLabel = input[lineIter];
        currentOpcode = input[lineIter + 1];
        currentOperand = input[lineIter + 2];
    }

    while (currentOpcode != "END" && lineIter < input.size()) {

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

    programLength = locCounter - startAddress;
    std::cout << "Program Length: " << std::setfill('0') << std::setw(4) << std::hex << programLength << std::endl;
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
            passOne(inputVector, optTable, symTable);
        }

        else {
            throw std::invalid_argument("File was not found.");
        }
    }
}
