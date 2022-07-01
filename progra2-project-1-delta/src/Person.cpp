//
// Created by Xarthy on 0016 April 16, 2022.
//

#include "Person.h"

Person::Person() = default;

Person::Person(int id) : id(id) {}

Person::~Person() = default;

int Person::getId() const {
    return id;
}

void Person::setId(int id) {
    Person::id = id;
}

std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << " id: " << person.id;
    return os;
}

std::string Person::toString() {
    std::stringstream s;
    s << (*this);
    return s.str();
}
