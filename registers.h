#include <vector>
#include "symbol.h"

class Registers {
    public:
        bool isRegister(std::string regName);
        Symbol getRegister(std::string regName);
    
    private:
        std::vector<Symbol> registers = {
            Symbol("A", 0, "0"),
            Symbol("X", 1, "0"),
            Symbol("L", 2, "0"),
            Symbol("PC", 8, "0"),
            Symbol("SW", 9, "0"),
            Symbol("B", 3, "0"),
            Symbol("S", 4, "0"),
            Symbol("T", 5, "0"),
            Symbol("F", 6, "0"),
        };
    
};