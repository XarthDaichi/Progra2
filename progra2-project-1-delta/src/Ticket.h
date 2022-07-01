//
// Created by Xarthy on 0016 April 16, 2022.
//

#ifndef PROGRA2_PROJECT_1_DELTA_TICKET_H
#define PROGRA2_PROJECT_1_DELTA_TICKET_H

#include <ostream>
#include "Object.h"
#include "Passenger.h"
#include "Route.h"

class Ticket : public Object {
private:
    Passenger buyer;
    Route route;
    string bus;
    int seats;
    string seatNumbers;
public:
    Ticket() = default;
    Ticket(const Passenger &buyer, const Route& route, string bus, int seats, string seatNumbers);

    virtual ~Ticket();

    int getSeats() const;

    void setSeats(int seats);

    const Passenger &getBuyer() const;

    void setBuyer(const Passenger &buyer);

    Route getRoute() const;

    void setRoute(Route route);

    const string &getBus() const;

    void setBus(const string &bus);

    const string &getSeatNumbers() const;

    void setSeatNumbers(const string &seatNumbers);

    friend ostream &operator<<(ostream &os, const Ticket &ticket);

    std::string toString() override;
};


#endif //PROGRA2_PROJECT_1_DELTA_TICKET_H
