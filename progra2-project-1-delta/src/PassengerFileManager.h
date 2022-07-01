//
// Created by Xarthy on 0013 May 13, 2022.
//

#ifndef PROGRA2_PROJECT_1_DELTA_PASSENGERFILEMANAGER_H
#define PROGRA2_PROJECT_1_DELTA_PASSENGERFILEMANAGER_H
#include "SingletonFileManager.h"
#include "Passenger.h"

class PassengerFileManager final : public SingletonFileManager<PassengerFileManager> {
private:
    Container<Passenger>* passengers;
    char inputType;
public:
    PassengerFileManager(const char c);
    virtual ~PassengerFileManager();

    void setInputType(char inputType);

    Container<Passenger>* getPassengers();

    static ostream& write(ostream& out, const Passenger& passenger);
    static istream& read(istream& in, Passenger& passenger);
};


#endif //PROGRA2_PROJECT_1_DELTA_PASSENGERFILEMANAGER_H
