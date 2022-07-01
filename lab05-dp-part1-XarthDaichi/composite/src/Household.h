//
// Created by Xarthy on 0021 May 21, 2022.
//

#ifndef COMPOSITE_HOUSEHOLD_H
#define COMPOSITE_HOUSEHOLD_H

#include <ostream>
#include "Person.h"

class Household : public Person {
private:
    vector<Person *> householdPeople;
public:
    Household();

    virtual ~Household();

    void add(Person *person) override;

    void remove(Person * person) override;

    vector<Person*> reports() const override;

    friend ostream &operator<<(ostream &os, const Household &household);
};


#endif //COMPOSITE_HOUSEHOLD_H
