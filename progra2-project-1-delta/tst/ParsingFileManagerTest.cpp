//
// Created by ribre on 13/05/2022.
//
#include "gtest/gtest.h"
#include "../src/VehicleFileManager.h"
#include "../src/RouteFileManager.h"
#include "../src/TicketFileManager.h"
#include "../src/PassengerFileManager.h"

TEST(FileGeneratorSuite, FileGeneration) {
    ofstream out;

    // creating bin vehicle file
    string fileName = "../../db_vehicle.dat";
    out.open(fileName, ios::trunc | ios::out | ios::binary);
    Bus * b1 = new Bus("Buseta","BUS001");
    Bus * b2 = new Bus("Buseta","BUS002");
    Bus * b3 = new Bus("Buseta","BUS003");
    Bus * b4 = new Bus("Coaster","COA001");
    Bus * b5 = new Bus("Coaster","COA002");
    Bus * b6 = new Bus("Hiace","HIA001");
    Bus * b7 = new Bus("Hiace","HIA002");
    Bus * b8 = new Bus("Hiace","HIA003");
    Bus * b9 = new Bus("Hiace","HIA004");
    Bus * b10 = new Bus("H1","HON001");
    Bus * b11 = new Bus("H1","HON002");
    vector<Vehicle*> tempVroom;
    tempVroom.push_back(b1);
    tempVroom.push_back(b2);
    tempVroom.push_back(b3);
    tempVroom.push_back(b4);
    tempVroom.push_back(b5);
    tempVroom.push_back(b6);
    tempVroom.push_back(b7);
    tempVroom.push_back(b8);
    tempVroom.push_back(b9);
    tempVroom.push_back(b10);
    tempVroom.push_back(b11);

    for (auto *i : tempVroom) {
        out.write((char*)&*i, sizeof(*i));
    }
    out.close();

    // creating bin route file
    fileName = "../../db_route.dat";
    out.open(fileName, ios::trunc | ios::out | ios::binary);
    tempVroom.clear();
    tempVroom.push_back(b1);
    tempVroom.push_back(b2);
    Route * r1 = new Route("Volcán Arenal","San Carlos",tempVroom);
    tempVroom.clear();
    tempVroom.push_back(b3);
    tempVroom.push_back(b4);
    Route * r2 = new Route("Río Celeste","San Carlos", tempVroom);
    tempVroom.clear();
    tempVroom.push_back(b5);
    tempVroom.push_back(b6);
    Route * r3 = new Route("Tamarindo","Guanacaste", tempVroom);
    tempVroom.clear();
    tempVroom.push_back(b7);
    tempVroom.push_back(b8);
    Route * r4 = new Route("Puerto Viejo","Limón", tempVroom);
    tempVroom.clear();
    tempVroom.push_back(b9);
    tempVroom.push_back(b10);
    Route * r5 = new Route("Cóbano","Puntarenas", tempVroom);
    tempVroom.clear();
    tempVroom.push_back(b10);
    Route * r6 = new Route("Volcán Irazú","Cartago", tempVroom);
    vector<Route*> tempWhereRUGoing;
    tempWhereRUGoing.push_back(r1);
    tempWhereRUGoing.push_back(r2);
    tempWhereRUGoing.push_back(r3);
    tempWhereRUGoing.push_back(r4);
    tempWhereRUGoing.push_back(r5);
    tempWhereRUGoing.push_back(r6);
    for (auto *i : tempWhereRUGoing) {
        out.write((char*)&*i, sizeof(*i));
    }
    out.close();

    // creating bin passenger file
    fileName = "../../db_passenger.dat";
    out.open(fileName, ios::trunc | ios::out | ios::binary);
    vector<Passenger*> tempAttentionPassengers;
    Passenger * p1 = new Passenger(1);
    Passenger * p2 = new Passenger(2);
    Passenger * p3 = new Passenger(3);
    Passenger * p4 = new Passenger(4);
    Passenger * p5 = new Passenger(5);
    Passenger * p6 = new Passenger(6);
    Passenger * p7 = new Passenger(7);
    tempAttentionPassengers.push_back(p1);
    tempAttentionPassengers.push_back(p2);
    tempAttentionPassengers.push_back(p3);
    tempAttentionPassengers.push_back(p4);
    tempAttentionPassengers.push_back(p5);
    tempAttentionPassengers.push_back(p6);
    tempAttentionPassengers.push_back(p7);
    for (auto * i : tempAttentionPassengers) {
        out.write((char*)&*i, sizeof(*i));
    }

    out.close();

    // creating bin ticket file
    fileName = "../../db_ticket.dat";
    out.open(fileName, ios::trunc | ios::out | ios::binary);
    vector<Ticket*> tempGoldenTickets;
    Ticket* t1 = new Ticket(*p1, *r1, b1->getLicencePlate(), 2, "1 2");
    Ticket* t2 = new Ticket(*p2, *r1, b2->getLicencePlate(), 3, "1 2 3");
    Ticket* t3 = new Ticket(*p3, *r2, b3->getLicencePlate(), 4, "1 2 3 4");
    Ticket* t4 = new Ticket(*p4, *r3, b5->getLicencePlate(), 5, "1 2 3 4 5");
    Ticket* t5 = new Ticket(*p5, *r4, b7->getLicencePlate(), 6, "1 2 3 4 5 6");
    Ticket* t6 = new Ticket(*p6, *r5, b9->getLicencePlate(), 7, "1 2 3 4 5 6 7");
    Ticket* t7 = new Ticket(*p7, *r6, b11->getLicencePlate(), 6, "1 2 3 4 5 6");
    tempGoldenTickets.push_back(t1);
    tempGoldenTickets.push_back(t2);
    tempGoldenTickets.push_back(t3);
    tempGoldenTickets.push_back(t4);
    tempGoldenTickets.push_back(t5);
    tempGoldenTickets.push_back(t6);
    tempGoldenTickets.push_back(t7);

    for (auto * i : tempGoldenTickets) {
        out.write((char*)&*i, sizeof(*i));
    }

    out.close();
}

TEST(ParsingFileManagerTestSuite, FileManagerParsing) {

    EXPECT_TRUE(VehicleFileManager::getInstance().getVehicles()->allObjects().size() == 11);
    EXPECT_EQ(VehicleFileManager::getInstance().getVehicles()->allObjects().at(0)->getType(),"Buseta");
    EXPECT_EQ(VehicleFileManager::getInstance().getVehicles()->allObjects().at(0)->getLicencePlate(),"BUS001");
    EXPECT_EQ(VehicleFileManager::getInstance().getVehicles()->allObjects().at(10)->getType(),"H1");
    EXPECT_EQ(VehicleFileManager::getInstance().getVehicles()->allObjects().at(10)->getLicencePlate(),"HON002");

    EXPECT_TRUE(PassengerFileManager::getInstance().getPassengers()->allObjects().size() == 7);
    EXPECT_EQ(PassengerFileManager::getInstance().getPassengers()->allObjects().at(0)->getId(),1);
    EXPECT_EQ(PassengerFileManager::getInstance().getPassengers()->allObjects().at(5)->getId(),6);

    EXPECT_TRUE(RouteFileManager::getInstance().getRoutes()->allObjects().size() == 6);
    EXPECT_EQ(RouteFileManager::getInstance().getRoutes()->allObjects().at(2)->getOrigin(),"Tamarindo");
    EXPECT_EQ(RouteFileManager::getInstance().getRoutes()->allObjects().at(2)->getDestination(),"Guanacaste");
    EXPECT_EQ(RouteFileManager::getInstance().getRoutes()->allObjects().at(2)->getVehicles().at(0)->getType(), "Coaster");
    EXPECT_EQ(RouteFileManager::getInstance().getRoutes()->allObjects().at(2)->getVehicles().at(0)->getLicencePlate(), "COA002");
    EXPECT_EQ(RouteFileManager::getInstance().getRoutes()->allObjects().at(2)->getVehicles().at(1)->getType(), "Hiace");
    EXPECT_EQ(RouteFileManager::getInstance().getRoutes()->allObjects().at(2)->getVehicles().at(1)->getLicencePlate(), "HIA001");

    EXPECT_TRUE(TicketFileManager::getInstance().getTickets()->allObjects().size() == 7);
    EXPECT_EQ(TicketFileManager::getInstance().getTickets()->allObjects().at(0)->getBuyer().getId(), 1);
    EXPECT_EQ(TicketFileManager::getInstance().getTickets()->allObjects().at(0)->getRoute().getOrigin(),"Volcán Arenal");
    EXPECT_EQ(TicketFileManager::getInstance().getTickets()->allObjects().at(0)->getRoute().getDestination(),"San Carlos");
    EXPECT_EQ(TicketFileManager::getInstance().getTickets()->allObjects().at(0)->getBus(), "BUS001");
    EXPECT_EQ(TicketFileManager::getInstance().getTickets()->allObjects().at(0)->getSeats(), 2);
    EXPECT_EQ(TicketFileManager::getInstance().getTickets()->allObjects().at(0)->getSeatNumbers(), "1 2");
}