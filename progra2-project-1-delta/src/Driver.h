//
// Created by ribre on 26/04/2022.
//

#ifndef PROGRA2_PROJECT_1_DELTA_DRIVER_H
#define PROGRA2_PROJECT_1_DELTA_DRIVER_H

#include <ostream>
#include "Person.h"

class Driver : public Person {
private:
//n
public:
    Driver();

    explicit Driver(int id);

    ~Driver() override;

    friend std::ostream &operator<<(std::ostream &os, const Driver &driver);

    std::string toString() override;
};


#endif //PROGRA2_PROJECT_1_DELTA_DRIVER_H
