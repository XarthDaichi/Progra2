//
// Created by Dell on 20/6/2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_EXECUTIVE_H
#define PROGRA_PROJECT_2_DELTA_EXECUTIVE_H

#include "Garment.h"
#include "IGarment.h"

class Executive :
        public Garment, public IGarment {
public:
    Executive();
    Executive(string, string, string, string, bool);
    ~Executive() override;

    string showCharacteristic() override;
};


#endif //PROGRA_PROJECT_2_DELTA_EXECUTIVE_H
