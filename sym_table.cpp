#include "sym_table.h"
#include <limits.h>

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

/*
    Method to determine if a mnemonic is in the symTable.
    Returns: index of symbol if found, MAX_INT if not found
*/
int SymTable::isInSymTable(std::string symbol) {
    for (int i = 0; i < symTable.size(); ++i) {
        if (symTable[i].getLabel() == symbol) {
            return i;
        }
    }
    return INT_MAX;
}

/*
    Method to determine if a mnemonic is in the symTable.
    Returns: index of symbol if found, MAX_INT if not found
*/
Symbol SymTable::getSymbol(int index) {
    return symTable[index];
}