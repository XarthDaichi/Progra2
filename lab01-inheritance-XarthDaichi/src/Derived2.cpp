//
// Created by Xarthy on 0015 March 15, 2022.
//

#include "Derived2.h"

Derived2::Derived2() : Base(0) {}

Derived2::Derived2(int test) : Base(test) {}

Derived2::~Derived2() {}

void Derived2::do_something() {
    std::cout << "Derived2!!!" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Derived2 &derived2) {
    os << static_cast<const Base &>(derived2);
    return os;
}
