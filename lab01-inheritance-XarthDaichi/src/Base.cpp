//
// Created by Xarthy on 0015 March 15, 2022.
//

#include "Base.h"
Base::Base(int test) : test(test) {}

Base::~Base() {}

int Base::getTest() const {
    return test;
}

void Base::setTest(int test) {
    Base::test = test;
}

std::ostream &operator<<(std::ostream &os, const Base &base) {
    os << "test: " << base.test;
    return os;
}
