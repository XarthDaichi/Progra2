//
// Created by Xarthy on 0021 May 21, 2022.
//

#ifndef COMPOSITE_PERSON_H
#define COMPOSITE_PERSON_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <ostream>
using namespace std;

class Person {
private:
    string name;
    int age;
    int id;
public:
    Person();

    Person(const string &name, int age, int id);

    virtual ~Person();

    const string &getName() const;

    void setName(const string &name);

    int getAge() const;

    void setAge(int age);

    int getId() const;

    void setId(int id);

    friend ostream &operator<<(ostream &os, const Person &person);

    virtual void add(Person *person);
    virtual void remove(Person *person);
    virtual vector<Person *> reports() const = 0;
};


#endif //COMPOSITE_PERSON_H
