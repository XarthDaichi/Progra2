//
// Created by Xarthy on 0020 April 20, 2022.
//

#include "Person.h"

Person::Person() {}

Person::Person(const std::string &firstName, const std::string &lastName, int id, const std::string &email) : firstName(
        firstName), lastName(lastName), id(id), email(email) {}

Person::~Person() {

}

const std::string &Person::getFirstName() const {
    return firstName;
}

void Person::setFirstName(const std::string &firstName) {
    Person::firstName = firstName;
}

const std::string &Person::getLastName() const {
    return lastName;
}

void Person::setLastName(const std::string &lastName) {
    Person::lastName = lastName;
}

int Person::getId() const {
    return id;
}

void Person::setId(int id) {
    Person::id = id;
}

const std::string &Person::getEmail() const {
    return email;
}

void Person::setEmail(const std::string &email) {
    Person::email = email;
}

std::string Person::toString() const {
    std::stringstream s;
    s << (*this);
    return s.str();
}

std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << "firstName: " << person.firstName << ", lastName: " << person.lastName
       << ", id: " << person.id << ", email: " << person.email;
    return os;
}



