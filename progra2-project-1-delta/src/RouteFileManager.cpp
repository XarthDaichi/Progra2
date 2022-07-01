//
// Created by Xarthy on 0006 May 06, 2022.
//

#include "RouteFileManager.h"

RouteFileManager::RouteFileManager(const char c) : inputType(c) {
    routes = new Container<Route>;
    clog << "Constructing RouteFileManager" << endl;

    Route* route = new Route();

    string origin, destination, lenBussesStr, vehicleType, vehicleLicencePlate, newline;
    int lenBusses;

    string fileName = "../../db_route.";
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
        if (inputType == 'b') myReadFile.read((char*)&*route, sizeof(*route));
        else {
            getline(myReadFile, origin, ';');
            if (!origin.empty()) {
                getline(myReadFile, destination, ';');
                getline(myReadFile, lenBussesStr, ';');
                lenBusses = stoi(lenBussesStr);
                vector<Vehicle*> temp;
                for (int i = 0; i < lenBusses; i++) {
                    getline(myReadFile, vehicleType, ';');
                    getline(myReadFile, vehicleLicencePlate, ';');
                    temp.push_back(new Bus(vehicleType, vehicleLicencePlate));
                }
                route->setOrigin(origin);
                route->setDestination(destination);
                route->setVehicles(temp);
            }
            getline(myReadFile,newline, '\n');
        }
        if (!origin.empty() || inputType == 'b') routes->push(new Route(*route));
    }

    if (inputType == 'b') routes->pop();
    myReadFile.close();
    clog << "Finished constructing RouteFileManager" << endl;
}

RouteFileManager::~RouteFileManager() {
    clog << "Deconstructing RouteFileManager" << endl;

    vector<Route*> rou = routes->allObjects();
    string fileNameCSV = "../../db_route.csv", fileNameDAT = "../../db_route.dat";
    ofstream myWriteFileCSV, myWriteFileDAT;

    myWriteFileCSV.open(fileNameCSV, ios::trunc | ios::out);

    if(!myWriteFileCSV.is_open()) {
        throw invalid_argument("Could not open file [" +fileNameCSV + "]");
    }

    myWriteFileCSV << "origin;destination;lenVehicles;type;licencePlate;\n";

    for (auto * i : routes->allObjects()) {
        myWriteFileCSV << i->getOrigin() << ';' << i->getDestination() << ';' << i->getVehicles().size() << ';';
        for (auto *j : i->getVehicles()) myWriteFileCSV << j->getType() << ';' << j->getLicencePlate() << ';';
        myWriteFileCSV << '\n';
    }

    myWriteFileCSV.close();

    myWriteFileDAT.open(fileNameDAT, ios::trunc | ios::out | ios::binary);

    if (!myWriteFileDAT.is_open()) {
        throw invalid_argument("Could not open file [" +fileNameDAT + "]");
    }

    for (auto * i : routes->allObjects()) {
        myWriteFileDAT.write((char*)&*i, sizeof(*i));
    }

    myWriteFileDAT.close();

    clog << "Finished Deconstructing RouteFileManager" << endl;
}

Container<Route>* RouteFileManager::getRoutes() {
    clog << "In use" << endl;
    return routes;
}

void RouteFileManager::setInputType(char inputType) {
    clog << "Changing inputType" << endl;
    RouteFileManager::inputType = inputType;
}
