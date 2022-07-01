//
// Created by ribre on 26/04/2022.
//

#include "Passenger.h"

Passenger::Passenger(): Person(0) {
}

Passenger::Passenger(int id) : Person(id) {
}

Passenger::~Passenger() = default;

std::ostream &operator<<(std::ostream &os, const Passenger &passenger) {
    os <<static_cast<const Person &>(passenger);
    return os;
}

std::string Passenger::toString() {
    std::stringstream s;
    s << (*this);
    return s.str();
}
