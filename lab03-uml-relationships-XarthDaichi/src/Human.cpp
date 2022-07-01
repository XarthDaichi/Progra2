//
// Created by Xarthy on 0009 April 09, 2022.
//

#include "Human.h"

Human::Human() {}

Human::~Human() {

}

const std::string &Human::getName() const {
    return name;
}

void Human::setName(const std::string &name) {
    Human::name = name;
}

int Human::getAge() const {
    return age;
}

void Human::setAge(int age) {
    Human::age = age;
}

int Human::getId() const {
    return id;
}

void Human::setId(int id) {
    Human::id = id;
}

std::ostream &operator<<(std::ostream &os, const Human &human) {
    os << static_cast<const Object &>(human) << " name: " << human.name << " age: " << human.age << " id: " << human.id;
    return os;
}
