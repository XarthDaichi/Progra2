#pragma once

#include <ostream>
#include "Base.h"
//
// Created by Xarthy on 0015 March 15, 2022.
//

#ifndef LAB01_INHERITANCE_DERIVED2_H
#define LAB01_INHERITANCE_DERIVED2_H


class Derived2 final: public Base {
private:
public:
    Derived2();
    Derived2(int test);
    virtual ~Derived2();

    void do_something() override;

    friend std::ostream &operator<<(std::ostream &os, const Derived2 &derived2);
};


#endif //LAB01_INHERITANCE_DERIVED2_H
