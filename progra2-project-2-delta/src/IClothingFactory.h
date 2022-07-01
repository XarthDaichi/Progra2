//
// Created by Dell on 21/6/2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_ICLOTHINGFACTORY_H
#define PROGRA_PROJECT_2_DELTA_ICLOTHINGFACTORY_H

#include "Executive.h"
#include "Work.h"
#include "Sport.h"
#include "Suit.h"
#include "Set.h"

class IClothingFactory {
public:
    virtual ~IClothingFactory() = default;
    virtual IGarment* createShirt(string code, string color, string size, bool characteristic) = 0;
    virtual IGarment* createPant(string code, string color, string size, bool characteristic) = 0;
    virtual IGarment* createShoe(string code, string color, string size, bool characteristic) = 0;
    virtual ISuit* createSuit(string code, vector<Clothing*> has) = 0;
    virtual ISet* createSet(string code, vector<Clothing*> has) = 0;
};


#endif //PROGRA_PROJECT_2_DELTA_ICLOTHINGFACTORY_H
