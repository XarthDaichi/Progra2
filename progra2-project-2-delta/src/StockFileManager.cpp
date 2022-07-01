//
// Created by Xarthy on 0021 June 21, 2022.
//

#include "StockFileManager.h"

StockFileManager::StockFileManager(const char c) {
    info = new StockData();
    clog << "Constructing StockFileManager" << endl;
    string fileName = "../../db_stockdata.";    ifstream myReadFile;

    fileName += "dat";

    myReadFile.open(fileName, ios::in | ios::binary);

    if (!myReadFile.is_open()) throw invalid_argument("Could not open the file [" + fileName + "]");

    myReadFile.seekg(0);
//    else getline(myReadFile, type, '\n');

    while(myReadFile.good()) {
        myReadFile.read((char*)&*info, sizeof(*info));
    }
    myReadFile.close();
    clog << "Finished Constructing StockFileManager" << endl;
}

StockFileManager::~StockFileManager() {
    clog << "Deconstructing StockFileManager" << endl;

    string fileNameCSV = "../../db_stockdata.csv", fileNameDAT = "../../db_stockdata.dat";
    ofstream myWriteFileCSV, myWriteFileDAT;

    myWriteFileDAT.open(fileNameDAT, ios::trunc | ios::out | ios::binary);

    if (!myWriteFileDAT.is_open()) throw invalid_argument("Could not open file [" + fileNameDAT + "]");

    myWriteFileDAT.write((char*)&*info, sizeof(*info));

    myWriteFileDAT.close();

    clog << "Finished Deconstructing PruchaseFileManager" << endl;
}

bool StockFileManager::isInputType() const {
    return inputType;
}

void StockFileManager::setInfo(StockData *info) {
    StockFileManager::info = info;
}

StockData *StockFileManager::getInfo() {
    return info;
}
