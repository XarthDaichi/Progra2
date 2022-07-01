//
// Created by Xarthy on 0014 May 14, 2022.
//
#include "gtest/gtest.h"
#include "../src/VehicleFileManager.h"

TEST(VehicleFileManagerTestSuite, FileGenerator) {
    ofstream out;

    // creating vehicle file
    string fileName = "../../db_vehicle.csv";
    out.open(fileName, ios::trunc | ios::out);
    out << "type;LicencePlate\n";
    out << "Buseta;BUS001\n";
    out << "Buseta;BUS002\n";
    out << "Buseta;BUS003\n";
    out << "Coaster;COA001\n";
    out << "Coaster;COA002\n";
    out << "Hiace;HIA001\n";
    out << "Hiace;HIA002\n";
    out << "Hiace;HIA003\n";
    out << "Hiace;HIA004\n";
    out << "H1;HON001\n";
    out << "H1;HON002\n";

    out.close();
}

TEST(VehicleFileManagerTestSuite, VehicleFileManager) {
    vector<Vehicle*> vroom = VehicleFileManager::getInstance('c').getVehicles()->allObjects();

    EXPECT_TRUE(vroom.size() == 11);
}