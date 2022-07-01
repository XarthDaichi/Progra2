//
// Created by Xarthy on 0020 April 20, 2022.
//

#include "PersonManager.h"

PersonManager::PersonManager() {}

PersonManager::PersonManager(const std::vector<Person> &people) : people(people) {}

PersonManager::~PersonManager() {

}

const std::vector<Person> &PersonManager::getPeople() const {
    return people;
}

void PersonManager::setPeople(const std::vector<Person> &people) {
    PersonManager::people = people;
}

void PersonManager::addPerson(const Person &person) {
    PersonManager::people.push_back(person);
}

void PersonManager::removeLastPerson() {
    PersonManager::people.pop_back();
}

std::ostream &operator<<(std::ostream &os, const PersonManager &manager) {
    for (Person i : manager.people) {
        os << i << "---";
    }
    return os;
}

std::string PersonManager::toString() const {
    std::stringstream s;
    s << (*this);
    return s.str();
}