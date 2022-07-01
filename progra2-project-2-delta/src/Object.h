//
// Created by Xarthy on 0016 June 16, 2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_OBJECT_H
#define PROGRA_PROJECT_2_DELTA_OBJECT_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Object {
public:
    virtual ~Object() = default;
    virtual string toString() const = 0;
};


#endif //PROGRA_PROJECT_2_DELTA_OBJECT_H
