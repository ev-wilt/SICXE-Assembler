#include <vector>
#include "symbol.h"

class SymTable {
    public:
        bool insertSymbol(std::string label, int location, std::string value);
    
    private:
        std::vector<Symbol> symTable;
    
};