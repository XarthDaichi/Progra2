#pragma once

#include <ostream>
#include "Base.h"
//
// Created by Xarthy on 0015 March 15, 2022.
//

#ifndef LAB01_INHERITANCE_DERIVED1_H
#define LAB01_INHERITANCE_DERIVED1_H


class Derived1 final : public Base {
private:
public:
    Derived1();

    Derived1(int test);

    virtual ~Derived1();

    void do_something() override;

    friend std::ostream &operator<<(std::ostream &os, const Derived1 &derived1);
};


#endif //LAB01_INHERITANCE_DERIVED1_H
