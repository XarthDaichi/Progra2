//
// Created by Andres on 29/4/2022.
//

#ifndef PROGRA2_PROJECT_1_DELTA_PANDEMICVEHICLE_H
#define PROGRA2_PROJECT_1_DELTA_PANDEMICVEHICLE_H

#include <ostream>
#include "Vehicle.h"


class PandemicVehicle :
        public Vehicle {
private:
    Vehicle* vehicle;
    double capacityRate;
public:
    explicit PandemicVehicle(Vehicle *vehicle = nullptr, double capacityRate = 1);

    ~PandemicVehicle() override;

    Vehicle *getVehicle() const;

    void setVehicle(Vehicle *vehicle);

    double getCapacityRate() const;

    void setCapacityRate(double capacityRate);

    int getCapacity() override;

    friend ostream &operator<<(ostream &os, const PandemicVehicle &bus);

    string toString() override;
};


#endif //PROGRA2_PROJECT_1_DELTA_PANDEMICVEHICLE_H
