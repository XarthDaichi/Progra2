#include <iostream>
#include <fstream>
#include "VehicleFileManager.h"
using namespace std;

int main() {
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

    // creating vehicle file
    fileName = "../../db_vehicle.csv";
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

    Container<Vehicle> vroom = VehicleFileManager::getInstance('c').getVehicles();
    cout << vroom.toString() << endl;
    return 0;
}
