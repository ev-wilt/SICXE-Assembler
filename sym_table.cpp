#include "sym_table.h"

/*
    Adds a symbol to the symbol table.
    Returns: true if element was inserted, false if element was already in table
*/
bool SymTable::insertSymbol(std::string label, int location, std::string value) {
    for (Symbol curSymbol : symTable) {
        if (curSymbol.getLabel() == label) {
            return false;
        }
    }

    Symbol newSymbol = Symbol(label, location, value);
    symTable.push_back(newSymbol);
    return true;
}