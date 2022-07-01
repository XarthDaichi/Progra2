//
// Created by Xarthy on 0020 March 20, 2022.
//

#ifndef CLASESABSTRACTASEINTERFACES_PERSON_H // For future reference lines 5 and 6 work the same as #pragma once
#define CLASESABSTRACTASEINTERFACES_PERSON_H

#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person();

    Person(const string &name, int age);

    virtual ~Person();

    const string &getName() const;

    void setName(const string &name);

    int getAge() const;

    void setAge(int age);

    friend ostream &operator<<(ostream &os, const Person &person);
};


#endif //CLASESABSTRACTASEINTERFACES_PERSON_H
