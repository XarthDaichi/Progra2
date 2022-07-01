//
// Created by Xarthy on 0002 May 02, 2022.
//

#ifndef PROGRA2_PROJECT_1_DELTA_VEHICLEFILEMANAGER_H
#define PROGRA2_PROJECT_1_DELTA_VEHICLEFILEMANAGER_H
#include "SingletonFileManager.h"
#include "Bus.h"
#include "PandemicVehicle.h"

class VehicleFileManager final : public SingletonFileManager<VehicleFileManager> {
private:
    Container<Vehicle>* vehicles;
    char inputType; // Variable for save and read files
public:
    VehicleFileManager(const char c = 'b');
    virtual ~VehicleFileManager();

    void setInputType(char inputType);

    Container<Vehicle>* getVehicles();

    static ostream& write(ostream& out, const Vehicle& vehicle);
    static istream& read(istream& in, Vehicle& vehicle);
};


#endif //PROGRA2_PROJECT_1_DELTA_VEHICLEFILEMANAGER_H
