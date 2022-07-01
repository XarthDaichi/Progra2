//
// Created by Andres on 29/4/2022.
//

#include "PandemicVehicle.h"

PandemicVehicle::PandemicVehicle(Vehicle *vehicle, double capacityRate) : vehicle(vehicle), capacityRate(capacityRate) {
}

PandemicVehicle::~PandemicVehicle() {
    delete vehicle;
}

Vehicle *PandemicVehicle::getVehicle() const {
    return vehicle;
}

void PandemicVehicle::setVehicle(Vehicle *vehicle) {
    PandemicVehicle::vehicle = vehicle;
}

double PandemicVehicle::getCapacityRate() const {
    return capacityRate;
}

void PandemicVehicle::setCapacityRate(double capacityRate) {
    PandemicVehicle::capacityRate = capacityRate;
}

ostream &operator<<(ostream &os, const PandemicVehicle &bus) {
    os << static_cast<const Vehicle &>(bus) << ", vehicle: " << bus.vehicle << ", capacityRate: " << bus.capacityRate;
    return os;
}

string PandemicVehicle::toString() {
    stringstream ss;
    ss << (*this);
    return ss.str();
}

int PandemicVehicle::getCapacity() {
    return vehicle->getCapacity() * capacityRate;
}
