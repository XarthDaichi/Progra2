//
// Created by ribre on 26/04/2022.
//

#ifndef PROGRA2_PROJECT_1_DELTA_PASSENGER_H
#define PROGRA2_PROJECT_1_DELTA_PASSENGER_H

#include <ostream>
#include "Person.h"

class Passenger : public Person{
private:
public:
    Passenger();

    explicit Passenger(int id);

    ~Passenger() override;

    friend std::ostream &operator<<(std::ostream &os, const Passenger &passenger);

    std::string toString() override;
};


#endif //PROGRA2_PROJECT_1_DELTA_PASSENGER_H
