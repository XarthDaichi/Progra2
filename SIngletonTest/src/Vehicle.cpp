//
// Created by Xarthy on 0013 May 13, 2022.
//

#include "Vehicle.h"

#include <utility>

Vehicle::Vehicle(string type, string licencePlate) : type(std::move(type)), licencePlate(std::move(licencePlate)) {}

Vehicle::~Vehicle() {}

std::string Vehicle::toString() {
    std::stringstream s;
    s << (*this);
    return s.str();
}

int Vehicle::getCapacity() {
    return CapacityManager::capacity(Vehicle::type);
}

const string &Vehicle::getType() const {
    return type;
}

void Vehicle::setType(const string &type) {
    Vehicle::type = type;
}

const string &Vehicle::getLicencePlate() const {
    return licencePlate;
}

void Vehicle::setLicencePlate(const string &licencePlate) {
    Vehicle::licencePlate = licencePlate;
}

ostream &operator<<(ostream &os, const Vehicle &vehicle) {
    os << " type: " << vehicle.type << " licencePlate: "
       << vehicle.licencePlate;
    return os;
}