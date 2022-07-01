//
// Created by Xarthy on 0015 March 15, 2022.
//

#include "Derived1.h"
Derived1::Derived1() : Base(0) {}

Derived1::Derived1(int test) : Base(test) {}

Derived1::~Derived1() {}

void Derived1::do_something() {
    std::cout << "Derived1!!!" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Derived1 &derived1) {
    os << static_cast<const Base &>(derived1);
    return os;
}
