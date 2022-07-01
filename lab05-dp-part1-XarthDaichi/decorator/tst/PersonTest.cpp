//
// Created by Xarthy on 0020 May 20, 2022.
//

#include "../lib/catch2/catch.hh"
#include <sstream>
#include <string>
#include "Person.h"
#include "CostumePerson.h"

TEST_CASE("PersonTestSuite", "PersonTest") {
    Person person("Diego", 18);
    CostumePerson cperson(person, "Robin");

    stringstream s1;
    stringstream s2;
    s1 << person;
    s2 << cperson;

    REQUIRE(s1.str() == "name: Diego age: 18");
    REQUIRE(s2.str() == "name: Diego age: 18 costume: Robin");
}