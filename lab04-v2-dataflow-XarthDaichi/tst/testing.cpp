//
// Created by Xarthy on 0020 April 20, 2022.
//
#include "gtest/gtest.h"
#include "../src/FileManager.h"
#include "../src/Utils.h"
#include "../src/Object.h"
#include "../src/Person.h"
#include "../src/PersonManager.h"

using namespace std;

TEST(PersonManagerTestSuite, CheckPeopleVector) {
    Person person1;
    Person person2;
    Person person3;
    Person person4;

    person1.setFirstName("Laura");
    person1.setLastName("Grey");
    person1.setId(2070);
    person1.setEmail("laura@example.com");

    person2.setFirstName("Craig");
    person2.setLastName("Johnson");
    person2.setId(4081);
    person2.setEmail("craig@example.com");

    person3.setFirstName("Mary");
    person3.setLastName("Jenkins");
    person3.setId(9346);
    person3.setEmail("mary@example.com");

    person4.setFirstName("Jamie");
    person4.setLastName("Smith");
    person4.setId(5079);
    person4.setEmail("jamie@example.com");

    vector<Person> testingVector;
    testingVector.push_back(person1);
    testingVector.push_back(person2);
    testingVector.push_back(person3);
    testingVector.push_back(person4);

    PersonManager personManager;
    personManager.setPeople(testingVector);

    EXPECT_TRUE(personManager.getPeople().size() == 4);
}

TEST(CSVLoadingTestSuite, CheckLoadingCSV) {
    PersonManager personManager = FileManager::loadCSV("../../email.csv");

    EXPECT_TRUE(personManager.getPeople().size() == 4);
    EXPECT_STREQ(personManager.getPeople()[0].getFirstName().c_str(), "Laura");
    EXPECT_STREQ(personManager.getPeople()[0].getLastName().c_str(), "Grey");
    EXPECT_EQ(personManager.getPeople()[0].getId(), 2070);
    EXPECT_STREQ(personManager.getPeople()[0].getEmail().c_str(), "laura@example.com");
}

TEST(DATLoadingTestSuite, CheckLoadingandSavingDAT) {

    PersonManager personManagerCSV = FileManager::loadCSV("../../email.csv");

    FileManager::saveDAT("../../email.dat", personManagerCSV);

    PersonManager personManagerDAT = FileManager::loadDAT("../../email.dat");

    ostringstream objectData;
    objectData << personManagerDAT;

    EXPECT_STREQ(objectData.str().c_str(), "firstName: Laura, lastName: Grey, id: 2070, email: laura@example.com---"
                                           "firstName: Craig, lastName: Johnson, id: 4081, email: craig@example.com---"
                                           "firstName: Mary, lastName: Jenkins, id: 9346, email: mary@example.com---"
                                           "firstName: Jamie, lastName: Smith, id: 5079, email: jamie@example.com---");
}