//
// Created by Xarthy on 0013 May 13, 2022.
//

#ifndef SINGLETONTEST_VEHICLE_H
#define SINGLETONTEST_VEHICLE_H

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


#endif //SINGLETONTEST_VEHICLE_H
