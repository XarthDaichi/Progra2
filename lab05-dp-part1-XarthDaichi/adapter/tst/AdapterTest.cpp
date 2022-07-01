//
// Created by Xarthy on 0020 May 20, 2022.
//

#include "../lib/catch2/catch.hh"
#include "../src/IVideogameInDollar.h"
#include "../src/IVideogameInColon.h"
#include "../src/VideogameInColonClassAdapter.h"
#include "../src/VideogameInColonObjectAdapter.h"

TEST_CASE("AdapterTestSuite", "VideogameAdapter") {

    SECTION("Testing US Clients") {
        IVideogameInDollar *normalClient = new VideogameInDollar;
        Videogame test1 = normalClient->buyVideogame(39.99, "Star Wars Jedi: Fallen Order Deluxe Edition", "Respawn Entertainment");
        Videogame test2 = normalClient->buyVideogame(15.99,"Hollow Knight", "Team Cherry");

        REQUIRE(test1.getPriceDollar() == 39.99);
        REQUIRE(test2.getPriceDollar() == 15.99);
    }

    SECTION("Testing Costa Rican Clients with Class Adapter") {
        IVideogameInColon *adapterClassInterface = new VideogameInColonClassAdapter;
        Videogame test3 = adapterClassInterface->buyVideogameInColon(29000.00,
                                                                     "Star Wars Jedi: Fallen Order Deluxe Edition",
                                                                     "Respawn Entertainment");
        Videogame test4 = adapterClassInterface->buyVideogameInColon(6500.00, "Hollow Knight", "Team Cherry");

        REQUIRE(test3.getPriceDollar() == 43.5);
        REQUIRE(test4.getPriceDollar() == 9.75);
    }

    SECTION("Test Costa Rican Clients with Object Adapter") {
        IVideogameInColon *adapterObjectInterface = new VideogameInColonObjectAdapter;
        Videogame test5 = adapterObjectInterface->buyVideogameInColon(29000.00,
                                                                      "Star Wars Jedi: Fallen Order Deluxe Edition",
                                                                      "Respawn Entertainment");
        Videogame test6 = adapterObjectInterface->buyVideogameInColon(6500.00, "Hollow Knight", "Team Cherry");

        REQUIRE(test5.getPriceDollar() == 43.5);
        REQUIRE(test6.getPriceDollar() == 9.75);
    }
}