//
// Created by Xarthy on 0009 April 09, 2022.
//

#include "Object.h"

Object::Object() {}

Object::~Object() {

}

std::ostream &operator<<(std::ostream &os, const Object &object) {
    return os;
}
