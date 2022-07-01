//
// Created by Xarthy on 0013 May 13, 2022.
//

#include "TicketFileManager.h"

TicketFileManager::TicketFileManager(const char c) : inputType(c){
    tickets = new Container<Ticket>;
    clog << "Creating TicketFileManager" << endl;

    Ticket* ticket = new Ticket();

    string bus, seatsStr, seatNumbers, idStr, origin, destination, lenBussesStr, vehicleType, vehicleLicencePlate, newline;
    int lenBusses;

    string fileName = "../../db_ticket.";
    ifstream myReadFile;

    if (inputType == 'b') fileName += "dat";
    else fileName += "csv";

    myReadFile.open(fileName, ios::in | ios::binary);

    if (!myReadFile.is_open()) {
        throw invalid_argument("Could not open the file [" + fileName + "]");
    }

    if (inputType == 'b') myReadFile.seekg(0);
    else getline(myReadFile, vehicleType, '\n');

    while(myReadFile.good()) {
        if (inputType == 'b') myReadFile.read((char*)&*ticket, sizeof(*ticket));
        else {
            getline(myReadFile, idStr, ';');
            if (!idStr.empty()) {
                Passenger tempP(stoi(idStr));
                getline(myReadFile, origin, ';');
                getline(myReadFile, destination, ';');
                getline(myReadFile, lenBussesStr, ';');
                lenBusses = stoi(lenBussesStr);
                vector<Vehicle*> tempV;
                for (int i = 0; i < lenBusses; i++) {
                    getline(myReadFile, vehicleType, ';');
                    getline(myReadFile, vehicleLicencePlate, ';');
                    tempV.push_back(new Bus(vehicleType, vehicleLicencePlate));
                }
                Route tempR;
                tempR.setOrigin(origin);
                tempR.setDestination(destination);
                tempR.setVehicles(tempV);
                getline(myReadFile, bus, ';');
                getline(myReadFile, seatsStr, ';');
                getline(myReadFile, seatNumbers, '\r');
                ticket->setBuyer(tempP);
                ticket->setRoute(tempR);
                ticket->setBus(bus);
                ticket->setSeats(stoi(seatsStr));
                ticket->setSeatNumbers(seatNumbers);
            }
            getline(myReadFile, newline, '\n');
        }
        if (!idStr.empty() || inputType == 'b') tickets->push(new Ticket(*ticket));
    }

    if (inputType == 'b') tickets->pop();
    myReadFile.close();
    clog << "Finished Creating TicketFileManager" << endl;
}

TicketFileManager::~TicketFileManager() {
    clog << "Deconstructing TicketFileManager" << endl;

    vector<Ticket*> tic = tickets->allObjects();

    string fileNameCSV = "../../db_ticket.csv", fileNameDAT = "../../db_ticket.dat";
    ofstream myWriteFileCSV, myWriteFileDAT;

    myWriteFileCSV.open(fileNameCSV, ios::trunc | ios::out);

    if(!myWriteFileCSV.is_open()) {
        throw invalid_argument("Could not open file [" +fileNameCSV + "]");
    }

    myWriteFileCSV << "passengerId;origin;destination;lenVehicles;vehicles(type;licencePlate);bus;seats;seatNumbers\n";

    for (auto * i : tickets->allObjects()) {
        myWriteFileCSV << i->getBuyer().getId() << ';';
        myWriteFileCSV << i->getRoute().getOrigin() << ';' << i->getRoute().getDestination() << ';' << i->getRoute().getVehicles().size();
        for (auto *j : i->getRoute().getVehicles()) {
            myWriteFileCSV << j->getType() << ';' << j->getLicencePlate() << ';';
        }
        myWriteFileCSV << i->getBus() << ';' << i->getSeats() << ';' << i->getSeatNumbers() <<  '\n';
    }

    myWriteFileCSV.close();

    myWriteFileDAT.open(fileNameDAT, ios::trunc | ios::out | ios::binary);

    if (!myWriteFileDAT.is_open()) {
        throw invalid_argument("Could not open file [" +fileNameDAT + "]");
    }

    for (auto * i : tickets->allObjects()) {
        myWriteFileDAT.write((char*)&*i, sizeof(*i));
    }

    myWriteFileDAT.close();
    clog << "Finished Deconstructing TicketFileManager" << endl;
}

Container<Ticket>* TicketFileManager::getTickets() {
    clog << "In use" << endl;
    return tickets;
}

void TicketFileManager::setInputType(char inputType) {
    clog << "Changing input" << endl;
    TicketFileManager::inputType = inputType;
}
