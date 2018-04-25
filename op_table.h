#include <map>

class OpTable {
    public:
        bool isInOpTable(std::string mnemonic);
        int getOpcode(std::string mnemonic);
        int getFormat(std::string mnemonic);
        int getValue(std::string mnemonic);

    private:
        const std::map<std::string, std::pair <int, int> > opTable = {
            {"ADD", std::make_pair(0x18, 3)},
            {"ADDF", std::make_pair(0x58, 3)},
            {"ADDR", std::make_pair(0x90, 2)},
            {"AND", std::make_pair(0x40, 3)},
            {"CLEAR", std::make_pair(0xB4, 2)},
            {"COMP", std::make_pair(0x28, 3)},
            {"COMPF", std::make_pair(0x88, 3)},
            {"COMPR", std::make_pair(0xA0, 2)},
            {"DIV", std::make_pair(0x24, 3)},
            {"DIVF", std::make_pair(0x64, 3)},
            {"DIVR", std::make_pair(0x9C, 2)},
            {"FIX", std::make_pair(0xC4, 1)},
            {"FLOAT", std::make_pair(0xC0, 1)},
            {"HIO", std::make_pair(0xF4, 1)},
            {"J", std::make_pair(0x3C, 3)},
            {"JEQ", std::make_pair(0x30, 3)},
            {"JGT", std::make_pair(0x34, 3)},
            {"JLT", std::make_pair(0x38, 3)},
            {"JSUB", std::make_pair(0x48, 3)},
            {"LDA", std::make_pair(0x00, 3)},
            {"LDB", std::make_pair(0x68, 3)},
            {"LDCH", std::make_pair(0x50, 3)},
            {"LDF", std::make_pair(0x70, 3)},
            {"LDL", std::make_pair(0x08, 3)},
            {"LDS", std::make_pair(0x6C, 3)},
            {"LDT", std::make_pair(0x74, 3)},
            {"LDX", std::make_pair(0x04, 3)},
            {"LPS", std::make_pair(0xD0, 3)},
            {"MUL", std::make_pair(0x20, 3)},
            {"MULF", std::make_pair(0x60, 3)},
            {"MULR", std::make_pair(0x98, 2)},
            {"NORM", std::make_pair(0xC8, 1)},
            {"OR", std::make_pair(0x44, 3)},
            {"RD", std::make_pair(0xD8, 3)},
            {"RMO", std::make_pair(0xAC, 2)},
            {"RSUB", std::make_pair(0x4C, 3)},
            {"SHIFTL", std::make_pair(0xA4, 2)},
            {"SHIFTR", std::make_pair(0xA8, 2)},
            {"SIO", std::make_pair(0xF0, 1)},
            {"SSK", std::make_pair(0xEC, 3)},
            {"STA", std::make_pair(0x0C, 3)},
            {"STB", std::make_pair(0x78, 3)},
            {"STCH", std::make_pair(0x54, 3)},
            {"STF", std::make_pair(0x80, 3)},
            {"STI", std::make_pair(0xD4, 3)},
            {"STL", std::make_pair(0x14, 3)},
            {"STS", std::make_pair(0x7C, 3)},
            {"STSW", std::make_pair(0xE8, 3)},
            {"STT", std::make_pair(0x84, 3)},
            {"STX", std::make_pair(0x10, 3)},
            {"SUB", std::make_pair(0x1C, 3)},
            {"SUBF", std::make_pair(0x5C, 3)},
            {"SUBR", std::make_pair(0x94, 2)},
            {"SVC", std::make_pair(0xB0, 2)},
            {"TD", std::make_pair(0xE0, 3)},
            {"TIO", std::make_pair(0xF8, 1)},
            {"TIX", std::make_pair(0x2C, 3)},
            {"TIXR", std::make_pair(0xB8, 2)},
            {"WD", std::make_pair(0xDC, 3)}
        };
    
};