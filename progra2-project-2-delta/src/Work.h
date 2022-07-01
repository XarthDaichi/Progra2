//
// Created by Dell on 20/6/2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_WORK_H
#define PROGRA_PROJECT_2_DELTA_WORK_H

#include "Garment.h"
#include "IGarment.h"

class Work :
        public Garment, public IGarment {
public:
    Work();
    Work(string, string, string, string, bool);
    ~Work() override;

    string showCharacteristic() override;
};

#endif //PROGRA_PROJECT_2_DELTA_WORK_H
