#include "op_table.h"

/*
    Getter for the attributes of a given mnemonic.
    Returns: pair where first = opcode & second = instruction format
*/
std::pair <int,std::string> OpTable::getAttrs(std::string opCode) {
    return opTable.find(opCode)->second;
}