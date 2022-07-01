//
// Created by ribre on 13/05/2022.
//
#include "gtest/gtest.h"
#include "../src/PurchaseManager.h"

using namespace std;

TEST(PurchaseManagerTestSuite, TestWorkingPurchaseManagerExists) {

    Bus *b1 = new Bus("Buseta", "BUS001");
    Bus *b2 = new Bus("Coaster", "COA001");
    Bus *b3 = new Bus("H1", "HO1001");
    Bus *b4 = new Bus("Hiace", "HIA001");
    Container<Vehicle> containerBus;
    containerBus.push(b1);
    containerBus.push(b2);
    containerBus.push(b3);
    containerBus.push(b4);
//Creation of a Container for vehicle

    auto *r1 = new Route("Costa Rica", "Nicaragua", containerBus.certainObjects("Buseta"));
    auto *r2 = new Route("Puntarenas", "Guanacaste", containerBus.certainObjects("Coaster"));
    auto *r3 = new Route("San Jose", "Limon", containerBus.certainObjects("H1"));
    auto *r4 = new Route("San Jose", "Heredia", containerBus.certainObjects("Hiace"));
    auto *routeContainer = new Container<Route>;
    routeContainer->push(r1);
    routeContainer->push(r2);
    routeContainer->push(r3);
    routeContainer->push(r4);
//Creation of a Container for Route (notice the use of certainObjects to work with a specific vehicle)

    auto *ticketContainer = new Container<Ticket>;
    PurchaseManager purchaseManager(ticketContainer, routeContainer);
//Creation of a ticket Container and a Purchase manager to test working method

    //Route that is actually on the vector (Must return True)
    Route rSt("Puntarenas", "Guanacaste", containerBus.certainObjects("Coaster"));
    EXPECT_TRUE(purchaseManager.exists(rSt));
    Route rSt2("San Jose", "Heredia", containerBus.certainObjects("Hiace"));
    EXPECT_TRUE(purchaseManager.exists(rSt2));

    //Route that is not on the vector (Must return False)
    Route rStF("Puntarenas", "Guanacaste", containerBus.certainObjects("Hiace"));
    EXPECT_FALSE(purchaseManager.exists(rStF));
    //Which means it has correct access to the vector
}
TEST(PurchaseManagerTestSuite, TestWorkingPurchaseManagerPurchase){

    Bus *b1 = new Bus("Buseta", "BUS001");
    Bus *b2 = new Bus("Coaster", "COA001");
    Bus *b3 = new Bus("H1", "HO1001");
    Bus *b4 = new Bus("Hiace", "HIA001");
    Container<Vehicle> containerBus;
    containerBus.push(b1);
    containerBus.push(b2);
    containerBus.push(b3);
    containerBus.push(b4);
//Creation of a Container for vehicle

    auto *r1 = new Route("Costa Rica", "Nicaragua", containerBus.certainObjects("Buseta"));
    auto *r2 = new Route("Puntarenas", "Guanacaste", containerBus.certainObjects("Coaster"));
    auto *r3 = new Route("San Jose", "Limon", containerBus.certainObjects("H1"));
    auto *r4 = new Route("San Jose", "Heredia", containerBus.certainObjects("Hiace"));
    auto *routeContainer = new Container<Route>;
    routeContainer->push(r1);
    routeContainer->push(r2);
    routeContainer->push(r3);
    routeContainer->push(r4);
//Creation of a Container for Route (notice the use of certainObjects to work with a specific vehicle)

    auto *ticketContainer = new Container<Ticket>;
    PurchaseManager purchaseManager(ticketContainer, routeContainer);
//Creation of a ticket Container and a Purchase manager to test working method

    //First person to buy a ticket
    Passenger pT1(1098753);
    Route rSt("Puntarenas", "Guanacaste", containerBus.certainObjects("Coaster"));
    EXPECT_TRUE(purchaseManager.purchase(pT1,rSt,1));
    //Checking ticket working just fine
    EXPECT_EQ(ticketContainer->toString()," buyer:  id: 1098753 route:  origin: Puntarenas destination: "
      "Guanacaste bus: COA001 seats: 1 seatNumbers: 1 ");

    //Two people bought tickets in the same route
    Passenger pT2(3948721);
    EXPECT_TRUE(purchaseManager.purchase(pT2,rSt,1));
    //Checking ticket working just fine with two people innit
    EXPECT_EQ(ticketContainer->toString()," buyer:  id: 1098753 route:  origin: Puntarenas destination: Guanacaste bus: COA001 seats: 1 seatNumbers: 1 "
                                          " buyer:  id: 3948721 route:  origin: Puntarenas destination: Guanacaste bus: COA001 seats: 1 seatNumbers: 2 ");
}

TEST(PurchaseManagerTestSuite, DistributionTest) {
    auto* tickets = new Container<Ticket>;
    auto* routes = new Container<Route>;
    auto* purchaseManager = new PurchaseManager(tickets,routes);
    vector<Vehicle*> vehicles;

    vehicles.push_back(new Vehicle("H1","HON001"));
    vehicles.push_back(new Vehicle("H1","HON002"));

    routes->push(new Route("Volcán Arenal, San Carlos","Puerto Viejo, Limón",vehicles));

    purchaseManager->purchase(Passenger(1111),*routes->allObjects().at(0),5);
    purchaseManager->purchase(Passenger(2222),*routes->allObjects().at(0),2);
    purchaseManager->purchase(Passenger(3333),*routes->allObjects().at(0),1);

    EXPECT_EQ(tickets->allObjects().at(0)->getBus(),"HON001");
    EXPECT_EQ(tickets->allObjects().at(1)->getBus(),"HON002");
    EXPECT_EQ(tickets->allObjects().at(2)->getBus(),"HON001");
    EXPECT_FALSE(purchaseManager->purchase(Passenger(4444),*routes->allObjects().at(0),5));
}