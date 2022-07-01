//
// Created by Xarthy on 0020 May 20, 2022.
//

#ifndef DECORATOR_COSTUMEPERSON_H
#define DECORATOR_COSTUMEPERSON_H

#include <ostream>
#include "Person.h"

class CostumePerson : public Person {
private:
    const Person& person;
    string costume;
public:
    CostumePerson(const Person &person, const string &costume);

    virtual ~CostumePerson();

    const Person &getPerson() const;

    const string &getCostume() const;

    void setCostume(const string &costume);

    friend ostream &operator<<(ostream &os, const CostumePerson &person);
};


#endif //DECORATOR_COSTUMEPERSON_H
