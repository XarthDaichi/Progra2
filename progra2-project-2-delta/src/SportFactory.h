//
// Created by Dell on 21/6/2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_SPORTFACTORY_H
#define PROGRA_PROJECT_2_DELTA_SPORTFACTORY_H

#include "IClothingFactory.h"

class SportFactory
        : public IClothingFactory {
public:
    SportFactory();
    ~SportFactory() override;

    IGarment *createShirt(string code, string color, string size, bool characteristic) override;
    IGarment *createPant(string code, string color, string size, bool characteristic) override;
    IGarment *createShoe(string code, string color, string size, bool characteristic) override;
    ISuit *createSuit(string code, vector<Clothing*> has) override;
    ISet *createSet(string code, vector<Clothing*> has) override;
};


#endif //PROGRA_PROJECT_2_DELTA_SPORTFACTORY_H
