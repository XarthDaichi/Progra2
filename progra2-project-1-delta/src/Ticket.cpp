//
// Created by Xarthy on 0016 April 16, 2022.
//

#include "Ticket.h"

#include <utility>

Ticket::Ticket(const Passenger &buyer, const Route& route, string bus, int seats, string seatNumbers) : buyer(buyer), route(route), bus(std::move(bus)), seats(seats), seatNumbers(std::move(seatNumbers)) {

}

Ticket::~Ticket() = default;

const Passenger &Ticket::getBuyer() const {
    return buyer;
}

void Ticket::setBuyer(const Passenger &buyer) {
    Ticket::buyer = buyer;
}

Route Ticket::getRoute() const {
    return route;
}

void Ticket::setRoute(Route route) {
    Ticket::route = route;
}

int Ticket::getSeats() const {
    return seats;
}

void Ticket::setSeats(int seats) {
    Ticket::seats = seats;
}

const string &Ticket::getBus() const {
    return bus;
}

void Ticket::setBus(const string &bus) {
    Ticket::bus = bus;
}

const string &Ticket::getSeatNumbers() const {
    return seatNumbers;
}

void Ticket::setSeatNumbers(const string &seatNumbers) {
    Ticket::seatNumbers = seatNumbers;
}

ostream &operator<<(ostream &os, const Ticket &ticket) {
    os  << " buyer: " << ticket.buyer << " route: " << ticket.route << " bus: "
        << ticket.bus << " seats: " << ticket.seats << " seatNumbers: " << ticket.seatNumbers;
    return os;
}

std::string Ticket::toString() {
    std::stringstream s;
    s << " buyer: " << buyer << " route: " << route.toString() << " bus: " << bus << " seats: " << seats << " seatNumbers: " << seatNumbers;
    return s.str();
}
