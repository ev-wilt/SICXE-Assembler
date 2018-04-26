#include <vector>
#include "symbol.h"

class SymTable {
    public:
        bool insertSymbol(std::string label, int location, std::string value);
        int isInSymTable(std::string symbol);
        Symbol getSymbol(int index);
    
    private:
        std::vector<Symbol> symTable;
    
};