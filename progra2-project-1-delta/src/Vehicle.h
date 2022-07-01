//
// Created by ribre on 26/04/2022.
//

#ifndef PROGRA2_PROJECT_1_DELTA_VEHICLE_H
#define PROGRA2_PROJECT_1_DELTA_VEHICLE_H
//comment
#include <ostream>
#include "Object.h"
#include "CapacityManager.h"

using namespace std;
class Vehicle: public Object {
protected:
    string type;
    string licencePlate;
public:
    explicit Vehicle(string type = "", string licencePlate = "");

    virtual ~Vehicle();

    const string &getType() const;

    void setType(const string &type);

    const string &getLicencePlate() const;

    void setLicencePlate(const string &licencePlate);

    friend ostream &operator<<(ostream &os, const Vehicle &vehicle);

    std::string toString() override;

    virtual int getCapacity();
};


#endif //PROGRA2_PROJECT_1_DELTA_VEHICLE_H
