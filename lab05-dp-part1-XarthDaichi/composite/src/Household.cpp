//
// Created by Xarthy on 0021 May 21, 2022.
//

#include "Household.h"

Household::Household() {}

Household::~Household() {

}

void Household::add(Person *person) {
    householdPeople.push_back(person);
}

void Household::remove(Person * person) {
    auto it = householdPeople.begin();
    for (auto * i : householdPeople) {
        if (i->getName() == person->getName() && i->getId() == person->getId() && i->getAge() == person->getAge()) {
            householdPeople.erase(it);
        }
        it++;
    }
}

vector<Person *> Household::reports() const {
    return householdPeople;
}

ostream &operator<<(ostream &os, const Household &household) {
    os << "name: " << household.getName() << " id: " << household.getId()  << "-----------Household List: ";
    for (const auto &dependant : household.reports()) {

        os << *dependant << "-> Reporting [";
        if (dependant->reports().size() > 0) {
            for (const auto &person : dependant->reports()) {
                os << person->getName() << "(" << person->getId() << ")" << ", ";
            }
            os << "] ";
        } else {
            os << "none] ";
        }
    }
    return os;
}
