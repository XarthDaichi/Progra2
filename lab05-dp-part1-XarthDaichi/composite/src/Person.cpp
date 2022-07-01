//
// Created by Xarthy on 0021 May 21, 2022.
//

#include "Person.h"

Person::Person() {}

Person::Person(const string &name, int age, int id) : name(name), age(age), id(id) {}

Person::~Person() {

}

const string &Person::getName() const {
    return name;
}

void Person::setName(const string &name) {
    Person::name = name;
}

int Person::getAge() const {
    return age;
}

void Person::setAge(int age) {
    Person::age = age;
}

int Person::getId() const {
    return id;
}

void Person::setId(int id) {
    Person::id = id;
}

ostream &operator<<(ostream &os, const Person &person) {
    os << "name: " << person.name << " age: " << person.age << " id: " << person.id;
    return os;
}

void Person::add(Person *person) {

}

void Person::remove(Person *person) {

}
