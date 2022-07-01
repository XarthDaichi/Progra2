//
// Created by Dell on 20/6/2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_SPORT_H
#define PROGRA_PROJECT_2_DELTA_SPORT_H

#include "Garment.h"
#include "IGarment.h"

class Sport :
        public Garment, public IGarment {
public:
    Sport();
    Sport(string, string, string, string, bool);
    ~Sport() override;

    string showCharacteristic() override;
};


#endif //PROGRA_PROJECT_2_DELTA_SPORT_H
