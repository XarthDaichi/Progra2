//
// Created by Xarthy on 0021 May 21, 2022.
//

#ifndef COMPOSITE_DEPENDANT_H
#define COMPOSITE_DEPENDANT_H

#include <iostream>
using namespace std;

#include "Person.h"

class Dependant : public Person {
public:
    Dependant();

    Dependant(const string &name, int age, int id);

    virtual ~Dependant();

    vector<Person *> reports() const override;

    friend ostream &operator<<(ostream &os, const Dependant &dependant);

};


#endif //COMPOSITE_DEPENDANT_H
