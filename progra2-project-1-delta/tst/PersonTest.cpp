//
// Created by ribre on 11/05/2022.
//
#include "gtest/gtest.h"
#include "../src/Person.h"
#include "../src/Passenger.h"

using namespace std;

TEST(PersonTestSuite, TestWorkingPerson) {
//Testing a person is successfully created
    Person person(1098432);
    EXPECT_EQ(person.getId(),1098432);
}

TEST(PassengerTestSuite, TestWorkingPassenger) {
//Testing a passenger is successfully created
    Passenger passenger(305420696);
    EXPECT_EQ(passenger.getId(),305420696);
}