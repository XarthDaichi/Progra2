//
// Created by Xarthy on 0011 March 11, 2022.
//

#include "Dog.h"
Dog::Dog() {}
Dog::~Dog() {}
// void Dog::setX(int x) {X = x;}
// int Dog::getX() {return X;}
void Dog::display() {
    std::cout << "Dog!!!" << std::endl;
}

void Dog::setYears(int years) {
    Dog::years = years;
}
