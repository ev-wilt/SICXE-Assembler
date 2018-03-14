#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector<std::string> inputVector;
    std::vector<std::string>::iterator iter = inputVector.begin();

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
                            iter = inputVector.insert(iter, token);
                        }
                    }
                }
            }

            for (iter = inputVector.begin(); iter < inputVector.end(); ++iter) {
                std::cout << *iter << std::endl;
            }
        }

        else {
            throw std::invalid_argument("File was not found.");
        }
    }
}
