//
// Created by Xarthy on 0016 April 16, 2022.
//

#ifndef PROGRA2_PROJECT_1_DELTA_ROUTE_H
#define PROGRA2_PROJECT_1_DELTA_ROUTE_H

#include <ostream>
#include "Object.h"
#include "PandemicVehicle.h"
#include "Bus.h"

class Route : public Object {
private:
    std::string origin;
    std::string destination;
    std::vector<Vehicle*> vehicles;
public:
    Route();

    Route(std::string origin, std::string destination, std::vector<Vehicle *> busses);

    virtual ~Route();

    const std::string &getOrigin() const;

    void setOrigin(const std::string &origin);

    const std::string &getDestination() const;

    void setDestination(const std::string &destination);

    const std::vector<Vehicle *> &getVehicles() const;

    void setVehicles(const std::vector<Vehicle *> &vehicles);

    bool vehicleExists(Vehicle vehicle);

    friend std::ostream &operator<<(std::ostream &os, const Route &route);

    std::string toString() override;
};


#endif //PROGRA2_PROJECT_1_DELTA_ROUTE_H
