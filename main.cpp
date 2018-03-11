#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        throw std::invalid_argument("No file was specified.");
    }
    else {
        std::string currentLine = "";
        std::string token = "";
        std::ifstream file(argv[1]);
        if (file) {
            while (getline(file, currentLine, '\n')) {
                if (currentLine[0] != '.' && currentLine != "") {
                    std::stringstream lineStream(currentLine);
                    while (getline(lineStream, token, '\t')) {
                        if (token[0] != '.' && token != "") {
                            std::cout << token << std::endl;
                        }
                    }
                }
            }
        }
        else {
            throw std::invalid_argument("File was not found.");
        }
    }
}
