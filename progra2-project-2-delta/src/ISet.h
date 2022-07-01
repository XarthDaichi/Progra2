//
// Created by Dell on 21/6/2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_ISET_H
#define PROGRA_PROJECT_2_DELTA_ISET_H

#include <iostream>
#include "Garment.h"
#include "Suit.h"
using namespace std;

class ISet {
public:
    virtual ~ISet() = default;
    virtual Garment* SearchGarment(string) = 0;
};


#endif //PROGRA_PROJECT_2_DELTA_ISET_H
