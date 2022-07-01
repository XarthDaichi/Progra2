//
// Created by Xarthy on 0002 May 02, 2022.
//

#include "VehicleFileManager.h"

VehicleFileManager::VehicleFileManager(const char c) : inputType(c) {
    vehicles = new Container<Vehicle>;
    clog << "Constructing VehicleFileManager" << endl;

    Bus* vroom = new Bus();

    string vehicleType, vehicleLicencePlate, newline;
    string fileName = "../../db_vehicle.";
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
        if (inputType == 'b') {
            myReadFile.read((char*)&*vroom, sizeof(*vroom));
        } else {
            getline(myReadFile, vehicleType, ';');
            if (!vehicleType.empty()) {
                getline(myReadFile, vehicleLicencePlate, '\r');
                getline(myReadFile, newline, '\n');
            }
            vroom->setType(vehicleType);
            vroom->setLicencePlate(vehicleLicencePlate);
        }
        if (!vehicleType.empty() || !vroom->getType().empty()) vehicles->push(new Bus(*vroom));
    }

    if (inputType == 'b') vehicles->pop();
    myReadFile.close();
    clog << "Constructed VehicleFileManager" << endl;
}

VehicleFileManager::~VehicleFileManager() {
    clog << "Deconstructing VehicleFileManager" << endl;

    string fileNameCSV = "../../db_vehicle.csv", fileNameDAT = "../../db_vehicle.dat";
    ofstream myWriteFileCSV, myWriteFileDAT;

    myWriteFileCSV.open(fileNameCSV, ios::trunc | ios::out);

    if(!myWriteFileCSV.is_open()) {
        throw invalid_argument("Could not open file [" +fileNameCSV + "]");
    }

    myWriteFileCSV << "Type;LicencePlate\n";

    for (auto * i : vehicles->allObjects()) {
        myWriteFileCSV << i->getType() << ";" << i->getLicencePlate() << '\n';
    }

    myWriteFileCSV.close();

    myWriteFileDAT.open(fileNameDAT, ios::trunc | ios::out | ios::binary);

    if (!myWriteFileDAT.is_open()) {
        throw invalid_argument("Could not open file [" +fileNameDAT + "]");
    }

    for (auto * i : vehicles->allObjects()) {
        myWriteFileDAT.write((char*)&*i, sizeof(*i));
    }

    myWriteFileDAT.close();
    clog << "Deconstructed VehicleFileManager" << endl;
}

Container<Vehicle>* VehicleFileManager::getVehicles() {
    clog << "In use" << endl;
    return vehicles;
}

void VehicleFileManager::setInputType(char inputType) {
    clog << "Changing FileInput" << endl;
    VehicleFileManager::inputType = inputType;
}
