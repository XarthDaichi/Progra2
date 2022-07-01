//
// Created by Andres on 10/5/2022.
//

#ifndef PROGRA2_PROJECT_1_DELTA_PURCHASEMANAGER_H
#define PROGRA2_PROJECT_1_DELTA_PURCHASEMANAGER_H
#include "Container.h"
#include "Route.h"
#include "Ticket.h"

class PurchaseManager {
private:
    Container<Ticket>* tickets;
    Container<Route>* routes;
public:
    PurchaseManager(Container<Ticket>* &tickets, Container<Route>* &routes);
    virtual ~PurchaseManager();
    bool exists(Route);
    int amountOfPeople(const Route&, const string&);
    bool available(const Route&, string&, string&, int);
    bool purchase(const Passenger&, const Route&, int);
};


#endif //PROGRA2_PROJECT_1_DELTA_PURCHASEMANAGER_H
