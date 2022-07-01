//
// Created by ribre on 26/04/2022.
//

#include "Driver.h"

Driver::Driver(): Person(0){
}

Driver::Driver(int id) : Person(id) {
}

std::ostream &operator<<(std::ostream &os, const Driver &driver) {
    os <<static_cast<const Person &>(driver);
    return os;
}

std::string Driver::toString() {
    std::stringstream s;
    s << (*this);
    return s.str();
}

Driver::~Driver() = default;

