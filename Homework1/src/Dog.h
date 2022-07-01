#pragma once
//
// Created by Xarthy on 0011 March 11, 2022.
//

#ifndef HOMEWORK1_DOG_H
#define HOMEWORK1_DOG_H

#include "Animal.h"
class Dog : Animal {
private:
    int years;
public:
    Dog();
    virtual ~Dog();
    // void setX(int x);
    // int getX();
    virtual void display();

    void setYears(int years);
};


#endif //HOMEWORK1_DOG_H
