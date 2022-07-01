#pragma once
#include <iostream>
//
// Created by Xarthy on 0015 March 15, 2022.
//

#ifndef LAB01_INHERITANCE_BASE_H
#define LAB01_INHERITANCE_BASE_H


class Base {
protected:
    int test; // solo para tener algun atributo para hacer los get's y set's
public:
    Base(int test);

    virtual ~Base();

    int getTest() const;

    void setTest(int test);

    virtual void do_something() = 0;

    friend std::ostream &operator<<(std::ostream &os, const Base &base);
};


#endif //LAB01_INHERITANCE_BASE_H
