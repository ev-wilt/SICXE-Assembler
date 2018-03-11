#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        throw std::invalid_argument("No file was specified.");
    }
    else {
        std::string token;
        std::ifstream file(argv[1]);
        if (file) {
            while (getline(file, token, '\t')) {
                if (token[0] != '.') {
                    std::cout << token << std::endl;
                }
            }
        }
        else {
            throw std::invalid_argument("File was not found.");
        }
    }
}
