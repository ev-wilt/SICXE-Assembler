#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include "op_table.h"
#include "sym_table.h"

/*
    Implementation of the first pass algorithm. 
    When iterating through the input vector:
    i = current label
    i + 1 = current opcode
    i + 2 = current operand
*/
void passOne(std::vector<std::string> & input, std::unique_ptr<OpTable> & optTable, std::unique_ptr<SymTable> & symTable) {

    for (int i = 0; i < input.size(); i += 3) {
        int locCounter = 0;

        if (input[i + 1] == "START") {
            locCounter = std::stoi(input[i+2], nullptr, 16);
            // TODO: Write line to intermediate file
            std::cout << locCounter << std::endl;
        }

        if (input[i + 1] != "END") {
            if (input[i] != "") {
                if (symTable->insertSymbol == false) {
                    throw  std::invalid_argument("Symbol in memory location" + std::to_string(locCounter) + "was already in SYMTAB.");
                }
            }

        }
    }
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
