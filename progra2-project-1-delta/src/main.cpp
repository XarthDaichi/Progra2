//
// Created by Xarthy on 0016 April 16, 2022.
//
#include <fstream>
#include <string>
#include "Container.h"
#include "Bus.h"
#include "Route.h"
#include "Ticket.h"
#include "Passenger.h"
#include "PurchaseManager.h"
#include "VehicleFileManager.h"
#include "RouteFileManager.h"
#include "PassengerFileManager.h"
#include "TicketFileManager.h"
#include <cstdio>


void fileGenerator() {
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
    Ticket* t7 = new Ticket(*p7, *r6, b11->getLicencePlate(), 4, "1 2 3 4");
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


int main() {
    try {
        // generating files
        fileGenerator();


        // Decorating Containers t
        vector<Vehicle*> pandemicVroom;
        double capacityRate = 0.8;
        for (auto * i : VehicleFileManager::getInstance().getVehicles()->allObjects()) {
            auto* vroomTemp = new PandemicVehicle(i, capacityRate);
            pandemicVroom.push_back(vroomTemp);
        }
        for (int i = 0; i < VehicleFileManager::getInstance().getVehicles()->allObjects().size(); i++) VehicleFileManager::getInstance().getVehicles()->pop();
        for(auto *i : pandemicVroom) {
            VehicleFileManager::getInstance().getVehicles()->push(i);
        }

        for (auto * i : RouteFileManager::getInstance().getRoutes()->allObjects()) {
            pandemicVroom.clear();
            for (auto * j : i->getVehicles()) {
                auto* vroomTemp = new PandemicVehicle(j, capacityRate);
                pandemicVroom.push_back(vroomTemp);
            }
            i->setVehicles(pandemicVroom);
        }

        for (auto * i : TicketFileManager::getInstance().getTickets()->allObjects()) {
            pandemicVroom.clear();
            for (auto * j : i->getRoute().getVehicles()) {
                auto* vroomTemp = new PandemicVehicle(j, capacityRate);
                pandemicVroom.push_back(vroomTemp);
            }
            i->getRoute().setVehicles(pandemicVroom);
        }

        cout << "After Parsing and decorating" << endl;

        for (auto * i : TicketFileManager::getInstance().getTickets()->allObjects()) {
            cout << i->toString() << endl;
        }


        cout << "------------------------------------------" << endl;

        Container<Route>* whereRUGoing = RouteFileManager::getInstance().getRoutes();
        Container<Ticket>* goldenTickets = TicketFileManager::getInstance().getTickets();

        PurchaseManager purchaseManager(goldenTickets,whereRUGoing);

        auto* route = new Route(*RouteFileManager::getInstance().getRoutes()->allObjects().at(0));
        purchaseManager.purchase(Passenger(1111),*route,6);

        purchaseManager.purchase(Passenger(2222),*route,7);

        purchaseManager.purchase(Passenger(3333),*route,3);

        purchaseManager.purchase(Passenger(4444),*route,5);

        purchaseManager.purchase(Passenger(5555),*route,2);


        cout << "After purchases" << endl;
        for (auto *i : goldenTickets->allObjects()) {
            cout << i->toString() << endl;
        }

        cout << "------------------------------------------" << endl;

        cout << "After putting it back into the fileManagers" << endl;

        for (auto * i : TicketFileManager::getInstance().getTickets()->allObjects()) {
            cout << i->toString() << endl;
        }

    } catch(std::exception& ex) {
        std::cerr << ex.what() << '\n' << std::endl;
    }


    return 0;
}
