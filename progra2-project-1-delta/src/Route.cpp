//
// Created by Xarthy on 0016 April 16, 2022.
//

#include "Route.h"

#include <utility>

Route::Route() = default;

Route::Route(std::string origin, std::string destination, std::vector<Vehicle *> vehicles) : origin(std::move(
        origin)), destination(std::move(destination)), vehicles(std::move(vehicles)) {}

Route::~Route() = default;

const std::string &Route::getOrigin() const {
    return origin;
}

void Route::setOrigin(const std::string &origin) {
    Route::origin = origin;
}

const std::string &Route::getDestination() const {
    return destination;
}

void Route::setDestination(const std::string &destination) {
    Route::destination = destination;
}

const std::vector<Vehicle *> &Route::getVehicles() const {
    return vehicles;
}

void Route::setVehicles(const std::vector<Vehicle *> &vehicles) {
    Route::vehicles = vehicles;
}

bool Route::vehicleExists(Vehicle vehicle) {
    for (Vehicle* i : vehicles) {
        if (i->getType() == vehicle.getType() && i->getLicencePlate() == vehicle.getLicencePlate()) return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Route &route) {
    os << " origin: " << route.origin << " destination: " << route.destination;
    for (Vehicle* i : route.vehicles) {
        os << *i;
    }
    return os;
}

std::string Route::toString() {
    std::stringstream s;
    s << " origin: " << origin << " destination: " << destination;
    return s.str();
}

