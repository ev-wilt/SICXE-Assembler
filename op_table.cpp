#include "op_table.h"

/*
    Method to determine if a mnemonic is in the opTable.
    Returns: true if found, false if not found
*/
bool OpTable::isInOpTable(std::string mnemonic) {
    if (opTable.find(mnemonic) == opTable.end()) {
        return false;
    }
    return true;
}

/*
    Getter for the opcode of a given mnemonic.
    Returns: Opcode
*/
int OpTable::getOpcode(std::string mnemonic) {
    return opTable.find(mnemonic)->second.first;
}

/*
    Getter for the Instruction format of a given mnemonic.
    Returns: Instruction format
*/
int OpTable::getFormat(std::string mnemonic) {
    return opTable.find(mnemonic)->second.second;
}

/*
    Getter for the value of a given mnemonic.
    Returns: Value
*/
int OpTable::getValue(std::string mnemonic) {
    return opTable.find(mnemonic)->second.first;
}