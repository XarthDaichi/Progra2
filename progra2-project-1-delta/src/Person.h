//
// Created by Xarthy on 0016 April 16, 2022.
//

#ifndef PROGRA2_PROJECT_1_DELTA_PERSON_H
#define PROGRA2_PROJECT_1_DELTA_PERSON_H

#include <ostream>
#include "Object.h"

class Person : public Object {
private:
    int id;
public:
    Person();

    Person(int id);

    virtual ~Person();

    int getId() const;

    void setId(int id);

    friend std::ostream &operator<<(std::ostream &os, const Person &person);

    std::string toString() override;
};


#endif //PROGRA2_PROJECT_1_DELTA_PERSON_H
