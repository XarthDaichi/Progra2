//
// Created by Xarthy on 0020 May 20, 2022.
//

#include "CostumePerson.h"

CostumePerson::CostumePerson(const Person &person, const string &costume) : person(person), costume(costume) {}

CostumePerson::~CostumePerson() {

}

const Person &CostumePerson::getPerson() const {
    return person;
}

void CostumePerson::setCostume(const string &costume) {
    CostumePerson::costume = costume;
}

const string &CostumePerson::getCostume() const {
    return costume;
}

ostream &operator<<(ostream &os, const CostumePerson &person) {
    os << person.person << " costume: " << person.costume;
    return os;
}

