//
// Created by Xarthy on 0021 May 21, 2022.
//

#include "Guardian.h"

Guardian::Guardian() {}

Guardian::Guardian(const string &name, int age, int id) : Person(name, age, id) {}

Guardian::~Guardian() {

}

ostream &operator<<(ostream &os, const Guardian &guardian) {
    os << static_cast<const Person &>(guardian) << " dependants: ";
    for (const auto &dependant : guardian.reports()) {
        os << dependant->getName() << "(" << dependant->getId() << ")" << " - ";
    }
    return os;
}

void Guardian::add(Person *person) {
    dependants.push_back(person);
}

void Guardian::remove(Person *person) {
    auto it = dependants.begin();
    for (auto * i : dependants) {
        if (i->getName() == person->getName() && i->getId() == person->getId() && i->getAge() == person->getAge()) {
            dependants.erase(it);
        }
        it++;
    }
}

vector<Person *> Guardian::reports() const {
    return dependants;
}


