//
// Created by ribre on 13/05/2022.
//
#include "gtest/gtest.h"
#include "../src/PurchaseManager.h"

using namespace std;

TEST(GenericContainerTestSuite, TestWorkingContainers){

   //bus filled generic vector test

    Bus* b1 = new Bus("Buseta", "BUS001");
    Bus* b2 = new Bus("Coaster", "COA001");
    Bus* b3 = new Bus("H1", "HO1001");
    Bus* b4 = new Bus("Hiace", "HIA001");

    Container<Vehicle> containerBus;
    containerBus.push(b1);
    containerBus.push(b2);
    containerBus.push(b3);
    containerBus.push(b4);

    //route filled generic vector test

    auto* r1 = new Route("Costa Rica", "Panama", containerBus.allObjects());
    auto* r2 = new Route("Costa Rica", "Nicaragua", containerBus.certainObjects("Buseta"));
    auto* r3 = new Route("Puntarenas", "Guanacaste", containerBus.certainObjects("Coaster"));
    auto* r4 = new Route("San Jose", "Limon", containerBus.certainObjects("H1"));
    auto* r5 = new Route("San Jose", "Heredia", containerBus.certainObjects("Hiace"));

    Container<Route> routeContainer;
    routeContainer.push(r1);
    routeContainer.push(r2);
    routeContainer.push(r3);
    routeContainer.push(r4);
    routeContainer.push(r5);

    //Checking there is no unwanted members in the vector
    EXPECT_TRUE(containerBus.allObjects().size() == 4);
    EXPECT_STREQ(containerBus.toString().c_str()," type: Buseta licencePlate: BUS001 type: Coaster licencePlate: COA001 "
                                      "type: H1 licencePlate: HO1001 type: Hiace licencePlate: HIA001");
    //Checking there is no unwanted members in the vector
    EXPECT_TRUE(routeContainer.allObjects().size() == 5);
    EXPECT_STREQ(routeContainer.toString().c_str()," origin: Costa Rica destination: Panama origin: Costa Rica destination: Nicaragua origin: Puntarenas destination: Guanacaste origin: San Jose destination: Limon origin: San Jose destination: Heredia");
}

TEST(GenericContainerTestSuite, certainObjectsTest) {

    //Testing certainObjects capacity to find wanted objects
    Bus* b1 = new Bus("Buseta", "BUS001");
    Bus* b2 = new Bus("Coaster", "COA001");
    Bus* b3 = new Bus("Buseta", "BUS002");

    Container<Vehicle> containerBus;
    containerBus.push(b1);
    containerBus.push(b2);
    containerBus.push(b3);

    vector<Vehicle*> allObjectsV = containerBus.allObjects();

    EXPECT_TRUE(allObjectsV.size() == 3);

    vector<Vehicle*> testBuseta = containerBus.certainObjects("Buseta");

    EXPECT_TRUE(testBuseta.size() == 2);

    vector<Vehicle*> testb1 = containerBus.certainObjects(*b1);
    EXPECT_TRUE(testb1.size() == 1);

    Container<Route> routeContainer;
    Route* r1 = new Route("Costa Rica", "Panama", containerBus.allObjects());
    EXPECT_TRUE(r1->getVehicles().size() == 3);

    Route* r2 = new Route("Costa Rica", "Nicaragua", containerBus.certainObjects("Buseta"));
    EXPECT_TRUE(r2->getVehicles().size() == 2);

    Route* r3 = new Route("Puntarenas", "Guanacaste", containerBus.certainObjects("Coaster"));
    EXPECT_TRUE(r3->getVehicles().size() == 1);

    routeContainer.push(r1);
    routeContainer.push(r2);
    routeContainer.push(r3);

    vector<Route*> testCoaster = routeContainer.certainObjects("Coaster");
    EXPECT_TRUE(testCoaster.size() == 2);

    vector<Route*> testDestination = routeContainer.certainObjects("Nicaragua");
    EXPECT_TRUE(testDestination.size() == 1);

    vector<Route*> testRouteb1 = routeContainer.certainObjects(*b1);
    EXPECT_TRUE(testRouteb1.size() == 2);
}
