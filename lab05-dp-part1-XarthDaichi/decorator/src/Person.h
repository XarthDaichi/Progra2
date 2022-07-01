//
// Created by Xarthy on 0020 May 20, 2022.
//

#ifndef DECORATOR_PERSON_H
#define DECORATOR_PERSON_H

#include <iostream>
using namespace std;

class Person {
private:
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


#endif //DECORATOR_PERSON_H
