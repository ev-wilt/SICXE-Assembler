#include <map>

class SymTable {
    public:
        bool insertSymbol(std::string symbol, int location);
        int getAddress(std::string symbol);
    
    private:
        std::map<std::string, int> symTable = {
        };
    
};