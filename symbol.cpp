#include "symbol.h"

Symbol::Symbol(std::string label, int location, std::string value) {
    label = label;
    location = location;
    value = value;
}

std::string Symbol::getLabel() {
    return label;
}

int Symbol::getLocation() {
    return location;
}

std::string Symbol::getValue() {
    return value;
}
