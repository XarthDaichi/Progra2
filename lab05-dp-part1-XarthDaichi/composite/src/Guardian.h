//
// Created by Xarthy on 0021 May 21, 2022.
//

#ifndef COMPOSITE_GUARDIAN_H
#define COMPOSITE_GUARDIAN_H

#include <ostream>
#include "Person.h"

class Guardian : public Person {
private:
    vector<Person *> dependants;
public:
    Guardian();

    Guardian(const string &name, int age, int id);

    virtual ~Guardian();

    void add(Person * person) override;

    void remove(Person * person) override;

    vector<Person*> reports() const override;

    friend ostream &operator<<(ostream &os, const Guardian &guardian);
};


#endif //COMPOSITE_GUARDIAN_H
