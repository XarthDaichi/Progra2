//
// Created by ribre on 08/05/2022.
//
#include "gtest/gtest.h"
#include "../src/Vehicle.h"
#include "../src/Bus.h"
#include"../src/PandemicVehicle.h"

using namespace std;

TEST(VehicleTestSuite, TestWorkingVehicle){
//Testing data is being succesfully saved
 Vehicle vehicle("Buseta","21352464");
 int VehicleCapacity = vehicle.getCapacity();

    EXPECT_STREQ(vehicle.getType().c_str(),"Buseta");
    EXPECT_STREQ(vehicle.getLicencePlate().c_str(),"21352464");
    EXPECT_EQ(VehicleCapacity,40);
}

TEST(BusTestSuite, TestWorkingBus){
//Testing bus works the same way that vehicle, adding capacity
    Bus bus("Coaster","58247541");
    int BusCapacity = bus.getCapacity();

    EXPECT_STREQ(bus.getType().c_str(),"Coaster");
    EXPECT_STREQ(bus.getLicencePlate().c_str(),"58247541");
    EXPECT_EQ(BusCapacity,27);
}

TEST(PandemicVehicleTestSuite, TestWorkingPandemicVehicle){
//Testing the Decorator works fine
    auto* bus = new Vehicle("Hiace","80652467");
    int vehicle2Capacity = bus->getCapacity();

    PandemicVehicle pandemicVehicle;
    pandemicVehicle.setCapacityRate(0.8);
    pandemicVehicle.setVehicle(bus);
    double pandemicVehicleCapacity = pandemicVehicle.getCapacity();

    EXPECT_STREQ(bus->getType().c_str(),"Hiace");
    EXPECT_STREQ(bus->getLicencePlate().c_str(),"80652467");
    EXPECT_EQ(vehicle2Capacity,12);

    EXPECT_EQ(pandemicVehicle.getCapacityRate(),0.8);
    EXPECT_STREQ(pandemicVehicle.getVehicle()->getType().c_str(),"Hiace");
    EXPECT_STREQ(pandemicVehicle.getVehicle()->getLicencePlate().c_str(),"80652467");
    EXPECT_EQ(pandemicVehicleCapacity,9);
    //capacity must be different even tho it is the same vehicle because of the capacityRate (decorator)
    //Only the 80% of the PandemicVehicle is being available for buying
}