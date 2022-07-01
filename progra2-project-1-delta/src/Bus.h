//
// Created by Xarthy on 0016 April 16, 2022.
//

#ifndef PROGRA2_PROJECT_1_DELTA_BUS_H
#define PROGRA2_PROJECT_1_DELTA_BUS_H

#include "Vehicle.h"

using namespace std;
class Bus : public Vehicle {
private:

public:
    Bus();

    explicit Bus(const string& type, const std::string& licencePlate);

    ~Bus() override;

    friend ostream &operator<<(ostream &os, const Bus &bus);

    std::string toString() override;
};


#endif //PROGRA2_PROJECT_1_DELTA_BUS_H
