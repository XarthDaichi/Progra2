//
// Created by Dell on 20/6/2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_IGARMENT_H
#define PROGRA_PROJECT_2_DELTA_IGARMENT_H

#include <iostream>
using namespace std;

class IGarment {
public:
    virtual ~IGarment() = default;
    virtual string showCharacteristic() = 0;
};


#endif //PROGRA_PROJECT_2_DELTA_IGARMENT_H
