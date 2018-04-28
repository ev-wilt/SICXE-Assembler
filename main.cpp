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

/*
    Function to check if a given string is a number.
    Returns: false if not a number, true otherwise
*/
bool isNum(std::string input) {
    for (int i = 1; i < input.length(); ++i) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}

/*
    Parses the operand in pass two by commas.
    Returns: A vector with each element being an item in the operand
*/
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
void passOne(std::vector<std::string>& input, std::unique_ptr<OpTable>& opTable, std::unique_ptr<SymTable>& symTable, int& progLength, std::vector<int>& recordStarts) {
    std::ofstream output;
    output.open("intermediate.txt");
    std::string currentLabel = input[0];
    std::string currentOpcode = input[1];
    std::string currentOperand = input[2];
    int locCounter = 0;
    int recordCounter = 0;
    int lineIter = 0;

    output << "LOCCTR:" << std::endl;
    
    // Start algorithm when START is found
    if (currentOpcode == "START") {
        locCounter = std::stoi(currentOperand, nullptr, 16);
        recordStarts.push_back(locCounter);
        output << std::setfill('0') << std::setw(4) << std::hex << locCounter << std::endl;
        lineIter += 3;
        currentLabel = input[lineIter];
        currentOpcode = input[lineIter + 1];
        currentOperand = input[lineIter + 2];
    }

    // Continue while not END and there's still more input
    while (currentOpcode != "END" && lineIter < input.size()) {

        // Remove X from operand if inderect addressing is used
        if (currentOperand.size() > 1 && currentOperand.substr(currentOperand.size() - 2) == ",X") {
            currentOperand = currentOperand.substr(0, currentOperand.size() - 2);
        }

        // Insert symbol in SYMTAB if there's a label
        if (currentLabel != "") {
            if (symTable->insertSymbol(currentLabel, locCounter, currentOperand) == false) {
                throw  std::invalid_argument("Symbol" + currentLabel + " was already in SYMTAB.");
            }
        }

        // Trim extended instruction opcode if necessary
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

            // Trim operand down to only required characters
            trimmedOperand.erase(0, 2);
            trimmedOperand.erase(trimmedOperand.length() - 1, 1);
            if (currentOperand[0] == 'X') {
                for (int i : trimmedOperand) {
                    if (i % 2 == 0) {
                        constLength += 1;  
                    }
                }
                recordCounter += trimmedOperand.length();
            }

            else if (currentOperand[0] == 'C') {
                for (int i : trimmedOperand) {
                    constLength += 1;  
                }
                recordCounter += trimmedOperand.length();
            }
            locCounter += constLength;
        }

        // Do nothing if BASE or LTORG
        else if (currentOpcode == "BASE") {
            locCounter = locCounter;
        }
        else if (currentOpcode == "LTORG") {
            locCounter = locCounter;
        }
        else if (currentOpcode == "EQU") {
            // Parsing equations would be done here
            symTable->insertSymbol(currentLabel, locCounter, currentOperand);
        }
        else {
            throw  std::invalid_argument("OpCode " + currentOpcode + " was not in OPTAB.");
        }

        // Save start addresses for text records
        if (opTable->getFormat(currentOpcode)  == 1) {
            recordCounter += 2;
        }
        else if (opTable->getFormat(currentOpcode)  == 2) {
            recordCounter += 4;
        }
        else if (opTable->getFormat(currentOpcode)  == 3) {
            if (currentOpcode[0] == '+') {
                recordCounter += 6;
            }
            else {
                recordCounter += 8;
            }
        }

        output << std::setfill('0') << std::setw(4) << std::hex << locCounter << std::endl;

        lineIter += 3;
        
        // Save locCounter for pass 2 if necessary
        if (recordCounter >= 60) {
            recordStarts.push_back(locCounter);
            recordCounter = 0;
        }
        if (lineIter < input.size()) {
	        currentLabel = input[lineIter];
            currentOpcode = input[lineIter + 1];
       	    currentOperand = input[lineIter + 2];
        }
    }

    // Write last instruction location
    output << std::setfill('0') << std::setw(4) << std::hex << locCounter << std::endl;

    // Save and write program length
    progLength = locCounter - recordStarts[0];
    output << "Program Length: " << std::setfill('0') << std::setw(4) << std::hex << progLength << std::endl;
    output.close();
}

/*
    Implementation of the second pass algorithm. 
*/
void passTwo(std::vector<std::string>& input, std::unique_ptr<OpTable>& opTable, std::unique_ptr<SymTable>& symTable, int& progLength, std::vector<int>& recordStarts) {
    Registers registers;
    std::ofstream output;
    output.open("object.txt");
    std::string currentLabel = input[0];
    std::string currentOpcode = input[1];
    std::string textRecord = "";
    std::string textAddress = "";
    std::vector<std::string> currentOperand = parseOperand(input[2]);
    int locCounter = 0;
    int lineIter = 0;
    int recordIter = 0;

    // Start algorith at START
    if (currentOpcode == "START") {
        lineIter += 3;
        currentLabel = input[lineIter];
        currentOpcode = input[lineIter + 1];
        currentOperand = parseOperand(input[lineIter + 2]);
    }

    // Write header record
    output << "HCOPY" << " " << std::setfill('0') << std::setw(6) << std::hex << recordStarts[0];
    output << std::setfill('0') << std::setw(6) << std::hex << progLength << std::endl;

    // Continue while not END and there's still more input
    while (currentOpcode != "END" && lineIter < input.size()) {
        bool extendedFormat = false;
        bool immediateAddr = false;
        bool inderectAddr = false;
        std::stringstream outputStream;
        std::string objCode = "";

        // Trim opcode if it's extended format
        if (currentOpcode[0] == '+') {
            currentOpcode = currentOpcode.substr(1);
            extendedFormat = true;
        }

        if (opTable->isInOpTable(currentOpcode)) {
            for (int i = 0; i < currentOperand.size(); ++i) {

                // Check for immediate addressing
                if (currentOperand[i][0] == '#') {
                    currentOperand[i] = currentOperand[i].substr(1);
                    immediateAddr = true;
                }

                // Check for inderect addressing
                else if (currentOperand[i][0] == '@') {
                    currentOperand[i] = currentOperand[i].substr(1);
                    inderectAddr = true;
                }

                // Search for operand in SYMTAB, replace it with the symbols location if found
                int symbolIndex = symTable->isInSymTable(currentOperand[i]);
                if (symbolIndex != INT_MAX) {
                    currentOperand[i] = std::to_string(symTable->getSymbol(symbolIndex).getLocation());
                }

                // Throw error if operand is not a number or register
                else if (!isNum(currentOperand[i]) && !registers.isRegister(currentOperand[i])) {
                    throw  std::invalid_argument("Operand " + currentOperand[i] + " was not a symbol, a register, or a number.");
                }

            }

            // Assemble object code instruction based on opcode format
            if (opTable->getFormat(currentOpcode) == 1) {
                outputStream << std::setfill('0') << std::setw(2) << std::hex << opTable->getOpcode(currentOpcode);
                objCode = outputStream.str();
            }
            else if (opTable->getFormat(currentOpcode) == 2) {
                outputStream << std::setfill('0') << std::setw(2) << std::hex << opTable->getOpcode(currentOpcode);
                
                for (int i = 0; i < currentOperand.size(); ++i) {
                    outputStream << std::to_string(registers.getRegister(currentOperand[i]).getLocation());
                }
                if (currentOperand.size() == 1) {
                    outputStream << "0";
                }
                objCode = outputStream.str();   
            }
            else if (opTable->getFormat(currentOpcode) == 3) {
                int firstSixBits = opTable->getOpcode(currentOpcode);

                // n and i bits
                if (inderectAddr) {
                    firstSixBits += 0x2;
                }
                else if (immediateAddr) {
                    firstSixBits += 0x1;
                }
                else {
                    firstSixBits += 0x3;
                }
                outputStream << std::setfill('0') << std::setw(2) << std::hex << firstSixBits;

                int nextFourBits = 0x0;
                
                // x bit
                if (currentOperand[currentOperand.size() - 1] == "X") {
                    nextFourBits += 0x8;
                }

                // b and p bits would go here

                // e bit
                if (extendedFormat == true) {
                    nextFourBits += 0x1;
                }
                outputStream << std::hex << nextFourBits;

                // disp/address bits
                if (extendedFormat == true) {
                    outputStream << std::setfill('0') << std::setw(5) << std::hex << std::stoi(currentOperand[0]);
                }
                else {
                    outputStream << std::setfill('0') << std::setw(3) << std::hex << std::stoi(currentOperand[0]);
                }
                objCode = outputStream.str();
            }
        }

        // Convert constant to object code
        else if (currentOpcode == "WORD" || currentOpcode == "BYTE") {
            if (currentOperand[0][0] == 'X') {
                currentOperand[0] = currentOperand[0].substr(2, currentOperand[0].length() - 2);
            }
            else if (currentOperand[0][0] == 'C') {
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
        textRecord += objCode;
        // If text record is at limit, write it and start new text record
        if (textRecord.length() >= 60) {
            std::stringstream startAndLength;
            startAndLength << std::setfill('0') << std::setw(6) << std::hex << recordStarts[recordIter];
            startAndLength << std::setfill('0') << std::setw(3) << std::hex << textRecord.length();
            textRecord = "T" + startAndLength.str() + textRecord;
            output << textRecord << std::endl;
            textRecord = "";
            ++recordIter;
        }
        if (lineIter < input.size()) {
	        currentLabel = input[lineIter];
            currentOpcode = input[lineIter + 1];
       	    currentOperand = parseOperand(input[lineIter + 2]);
        }
    }

    // Write last text record
    std::stringstream startAndLength;
    startAndLength << std::setfill('0') << std::setw(6) << std::hex << recordStarts[recordIter];
    startAndLength << std::setfill('0') << std::setw(3) << std::hex << textRecord.length();
    textRecord = "T" + startAndLength.str() + textRecord;
    output << textRecord << std::endl;

    // Write end record
    output << "E" << std::setfill('0') << std::setw(6) << std::hex << recordStarts[0] << std::endl;
    output.close();
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

        // Parse file line by line, removing comments and saving tokens in vec
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
            std::vector<int> recordStarts;
            int progLength = 0;
            int startAddr = 0;
            passOne(inputVector, optTable, symTable, progLength, recordStarts);
            passTwo(inputVector, optTable, symTable, progLength, recordStarts);
        }

        else {
            throw std::invalid_argument("File was not found.");
        }
    }
}