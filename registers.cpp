#include "registers.h"

/*
    Determines if the given string is the label of a register.
    Returns: true if register was found, false otherwise
*/
bool Registers::isRegister(std::string regName) {
    for (Symbol curReg : registers) {
        if (curReg.getLabel() == regName) {
            return true;
        }
    }
    return false;
}

/*
    Getter for a given register.
    Returns: register of label regName if found
*/
Symbol Registers::getRegister(std::string regName) {
    for (Symbol curReg : registers) {
        if (curReg.getLabel() == regName) {
            return curReg;
        }
    }
}