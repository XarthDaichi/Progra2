//
// Created by Xarthy on 0013 May 13, 2022.
//

#include "Bus.h"

Bus::Bus(): Vehicle() {}

Bus::Bus(const string& type, const std::string& licencePlate):Vehicle(type, licencePlate) {
}

Bus::~Bus() = default;

ostream &operator<<(ostream &os, const Bus &bus) {
    os << static_cast<const Vehicle &>(bus);
    return os;
}

std::string Bus::toString() {
    std::stringstream s;
    s << (*this);
    return s.str();
}