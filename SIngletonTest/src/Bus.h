//
// Created by Xarthy on 0013 May 13, 2022.
//

#ifndef SINGLETONTEST_BUS_H
#define SINGLETONTEST_BUS_H

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

#endif //SINGLETONTEST_BUS_H
