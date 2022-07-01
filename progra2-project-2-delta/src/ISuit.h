//
// Created by Dell on 21/6/2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_ISUIT_H
#define PROGRA_PROJECT_2_DELTA_ISUIT_H

#include <iostream>
#include "Garment.h"
using namespace std;

class ISuit {
public:
    virtual ~ISuit() = default;
    virtual Garment* SearchGarment(string) = 0;
};


#endif //PROGRA_PROJECT_2_DELTA_ISUIT_H
