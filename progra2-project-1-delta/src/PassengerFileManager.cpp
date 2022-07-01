//
// Created by Xarthy on 0013 May 13, 2022.
//
#include "PassengerFileManager.h"

PassengerFileManager::PassengerFileManager(const char c) : inputType(c) {
    passengers = new Container<Passenger>;
    clog << "Constructing PassengerFileManager" << endl;

    Passenger* pass = new Passenger();
    int id;
    string idStr, newline;
    string fileName = "../../db_passenger.";
    ifstream myReadFile;

    if (inputType == 'b') fileName += "dat";
    else fileName += "csv";
    myReadFile.open(fileName, ios::in | ios::binary);

    if (!myReadFile.is_open()) {
        throw invalid_argument("Could not open the file [" + fileName + "]");
    }

    if (inputType == 'b') myReadFile.seekg(0);
    else getline(myReadFile, idStr, '\n');

    while(myReadFile.good()) {
        if (inputType == 'b') myReadFile.read((char*)&*pass, sizeof(*pass));
        else {
            getline(myReadFile, idStr, '\r');
            if (!idStr.empty()) pass->setId(stoi(idStr));
            getline(myReadFile, newline, '\n');
        }
        if (!idStr.empty() || inputType == 'b') passengers->push(new Passenger(*pass));
    }

    if (inputType == 'b') passengers->pop();
    myReadFile.close();
    clog << "Finished Constructing PassengerFileManager" << endl;
}

PassengerFileManager::~PassengerFileManager() {
    clog << "Deconstructing PassengerFileManager" << endl;

    string fileNameCSV = "../../db_passenger.csv", fileNameDAT = "../../db_passenger.dat";
    ofstream myWriteFileCSV, myWriteFileDAT;

    myWriteFileCSV.open(fileNameCSV, ios::trunc | ios::out);

    if(!myWriteFileCSV.is_open()) {
        throw invalid_argument("Could not open file [" +fileNameCSV + "]");
    }

    myWriteFileCSV << "Id\n";

    for (auto * i : passengers->allObjects()) {
        myWriteFileCSV << i->getId() << '\n';
    }

    myWriteFileCSV.close();

    myWriteFileDAT.open(fileNameDAT, ios::trunc | ios::out | ios::binary);

    if (!myWriteFileDAT.is_open()) {
        throw invalid_argument("Could not open file [" +fileNameDAT + "]");
    }

    for (auto * i : passengers->allObjects()) {
        myWriteFileDAT.write((char*)&*i, sizeof(*i));
    }

    myWriteFileDAT.close();
    clog << "Finished Deconstructing PassengerFileManager" << endl;
}

Container<Passenger>* PassengerFileManager::getPassengers() {
    clog << "In use" << endl;
    return passengers;
}

void PassengerFileManager::setInputType(char inputType) {
    clog << "Changing inputType" << endl;
    PassengerFileManager::inputType = inputType;
}

#include "PassengerFileManager.h"
