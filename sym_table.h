#include <vector>
#include "symbol.h"

class SymTable {
    public:
        bool insertSymbol(std::string label, int location, std::string value);
        int isInSymTable(std::string symbol);
        Symbol getSymbol(int index);
    
    private:
        std::vector<Symbol> symTable = {
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