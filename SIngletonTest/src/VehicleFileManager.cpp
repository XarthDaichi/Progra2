//
// Created by Xarthy on 0013 May 13, 2022.
//

#include "VehicleFileManager.h"

VehicleFileManager::VehicleFileManager(const char c) : inputType(c) {
    clog << "Constructing VehicleFileManager" << endl;

    string vehicleType, vehicleLicencePlate, newline;
    string fileName = "../../db_vehicle.";
    ifstream myReadFile;

    Bus* vroom;

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
            (*vroom).setType(vehicleType);
            (*vroom).setLicencePlate(vehicleLicencePlate);
        }
        if (!vehicleType.empty() || inputType == 'b') vehicles.push(new Bus(vroom->getType(), vroom->getLicencePlate()));
    }


    myReadFile.close();
    clog << "Constructed VehicleFileManager" << endl;
}

VehicleFileManager::~VehicleFileManager() {
    clog << "Deconstructing VehicleFileManager" << endl;

    string fileName = "../../db_vehicle.";
    ofstream myWriteFile;

    if (inputType == 'b') fileName += "dat";
    else fileName += "csv";

    myWriteFile.open(fileName, ios::trunc | ios::out | ios::binary);

    if(!myWriteFile.is_open()) {
        throw invalid_argument("Could not open file [" +fileName + "]");
    }

    if (inputType != 'b') myWriteFile << "Type;LicencePlate\n";

    for (auto * i : vehicles.allObjects()) {
        if (inputType == 'b') {
            myWriteFile.write((char*)&*i, sizeof(*i));
        } else {
            myWriteFile << i->getType() << ";" << i->getLicencePlate() << '\n';
        }
    }

    myWriteFile.close();
    clog << "Deconstructed VehicleFileManager" << endl;
}

Container<Vehicle> VehicleFileManager::getVehicles() {
    clog << "In use" << endl;
    return vehicles;
}

void VehicleFileManager::setInputType(char inputType) {
    clog << "Changing FileInput" << endl;
    VehicleFileManager::inputType = inputType;
}