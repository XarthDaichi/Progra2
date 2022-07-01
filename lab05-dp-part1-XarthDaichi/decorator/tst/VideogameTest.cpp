//
// Created by Xarthy on 0020 May 20, 2022.
//

#include "../lib/catch2/catch.hh"
#include <sstream>
#include "DigitalCopyVideogame.h"
#include "PhysicalCopyVideogame.h"
#include "DiscountedVideogame.h"


TEST_CASE("VideogameTestSuite","VideogameTest") {
    SECTION("Testing the string of the videogames") {
        DigitalCopyVideogame dVideogame("Star Wars Jedi: Fallen Order Deluxe Edition", "Respawn Entertainment", 39.99, "Steam");
        PhysicalCopyVideogame pVideogame("Hollow Knight", "Team Cherry", 9.99, "Walmart");

        stringstream s;
        s << dVideogame;
        REQUIRE(s.str() == "name: Star Wars Jedi: Fallen Order Deluxe Edition company: Respawn Entertainment price: 39.99 onlineRetailer: Steam");

        s.str("");
        s << pVideogame;
        REQUIRE(s.str() == "name: Hollow Knight company: Team Cherry price: 9.99 seller: Walmart");
    }

    SECTION("Testing strings on the discount videogame") {
        DigitalCopyVideogame dVideogame("Star Wars Jedi: Fallen Order Deluxe Edition", "Respawn Entertainment", 39.99, "Steam");
        PhysicalCopyVideogame pVideogame("Hollow Knight", "Team Cherry", 9.99, "Walmart");

        DiscountedVideogame disVideogame1(dVideogame, 0.80);
        DiscountedVideogame disVideogame2(pVideogame, 0.20);

        stringstream s;
        s << disVideogame1;
        REQUIRE(s.str() == "name: Star Wars Jedi: Fallen Order Deluxe Edition company: Respawn Entertainment price: 39.99 discount: 0.8 discountPrice: 7.998");

        s.str("");
        s << disVideogame2;
        REQUIRE(s.str() == "name: Hollow Knight company: Team Cherry price: 9.99 discount: 0.2 discountPrice: 7.992");
    }
}