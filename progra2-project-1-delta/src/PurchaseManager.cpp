//
// Created by Andres on 10/5/2022.
//

#include "PurchaseManager.h"

PurchaseManager::PurchaseManager(Container<Ticket>* &tickets, Container<Route>* &routes) : tickets(tickets),
                                                                                         routes(routes) {}

PurchaseManager::~PurchaseManager() = default;

bool PurchaseManager::exists(Route route) {
    return !routes->certainObjects(route).empty();
}

int PurchaseManager::amountOfPeople(const Route& route, const string& bus){
    vector<Ticket *> routeTickets = tickets->certainObjects(route);
    int count = 0;
    for(Ticket* i : routeTickets)
        if(i->getBus() == bus)
            count += i->getSeats();
    return count;
}

bool PurchaseManager::available(const Route& route, string& bus, string& seatNumbers, int spaces) {
    if(exists(route)) {
        vector<Vehicle *> vehicles = route.getVehicles();
        int people = 0;
        int capacity = 0;
        Vehicle* pandemic = nullptr;
        for(auto & vehicle : vehicles){
            people = amountOfPeople(route, vehicle->getLicencePlate());
            pandemic = dynamic_cast<PandemicVehicle*> (vehicle);
            if(pandemic) capacity = pandemic->getCapacity();
            else capacity = vehicle->getCapacity();
            if(capacity - people >= spaces) {
                stringstream ss;
                for (int i = 1; i <= spaces; i++) {
                    ss << people + i << " ";
                }
                seatNumbers = ss.str();
                bus = vehicle->getLicencePlate();
                return true;
            }
        }
        return false;
    }
    return false;
}

bool PurchaseManager::purchase(const Passenger& buyer, const Route& route, int seats) {
    string bus, seatNumbers;
    if(available(route,bus,seatNumbers,seats)){
        tickets->push(new Ticket(buyer,route,bus,seats,seatNumbers));
        return true;
    }
    return false;
}