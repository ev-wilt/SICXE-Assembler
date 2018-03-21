#include "sym_table.h"

/*
    Adds a symbol to the symbol table.
    Returns: true if element was inserted, false if element was already in table
*/
bool SymTable::insertSymbol(std::string symbol, int location) {
    std::pair <std::map <std::string, int>::iterator, bool> didInsert;
    didInsert = symTable.insert(std::pair <std::string, int>(symbol, location));
    if (didInsert.second == true) {
        return true;
    }
    else if (didInsert.second == false) {
        return false;
    }
}

/*
    Getter for the address of a given symbol.
    Returns: address of symbol
*/
int SymTable::getAddress(std::string symbol) {
    return symTable.find(symbol)->second;
}