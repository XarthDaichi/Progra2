//
// Created by Xarthy on 0014 May 14, 2022.
//
#include "gtest/gtest.h"
#include "../src/RouteFileManager.h"

TEST(RouteFileManagerTestSuite, FileGenerator) {
    // creating route file
    ofstream out;
    string fileName = "../../db_route.csv";
    out.open(fileName, ios::trunc | ios::out);

    out << "origin;destination;lenVehicles;type;licencePlate;\n";
    out << "Volcán Arenal;San Carlos;2;Buseta;BUS001;Buseta;BUS002;\n";
    out << "Río Celeste;San Carlos;2;Buseta;BUS003;Coaster;COA001;\n";
    out << "Tamarindo;Guanacaste;2;Coaster;COA002;Hiace;HIA001;\n";
    out << "Puerto Viejo;Limón;2;Hiace;HIA002;Hiace;HIA003;\n";
    out << "Cóbano;Puntarenas;2;Hiace;HIA004;H1;HON001;\n";
    out << "Volcán Irazú;Cartago;1;H1;HON002;\n";

    out.close();
}

TEST(RouteFileManagerTestSuite, RouteFileManager) {
    vector<Route*> whereRUGoing = RouteFileManager::getInstance('c').getRoutes()->allObjects();

    EXPECT_TRUE(whereRUGoing.size() == 6);
}