//
// Created by Xarthy on 0021 May 21, 2022.
//

#include "Dependant.h"


Dependant::Dependant() {}

Dependant::Dependant(const string &name, int age, int id) : Person(name, age, id) {}

Dependant::~Dependant() {

}

ostream &operator<<(ostream &os, const Dependant &dependant) {
    os << static_cast<const Person &>(dependant);
    return os;
}

vector<Person *> Dependant::reports() const {
    return vector<Person *>();
}
