//
// Created by Xarthy on 0014 May 14, 2022.
//
#include "gtest/gtest.h"
#include "../src/PassengerFileManager.h"

TEST(PassengerFileManagerTestSuite, FileGenerator) {
    // creating passenger file
    ofstream out;
    string fileName = "../../db_passenger.csv";
    out.open(fileName, ios::trunc | ios::out);

    out << "Id\n";
    out << "1\n";
    out << "2\n";
    out << "3\n";
    out << "4\n";
    out << "5\n";
    out << "6\n";
    out << "7\n";

    out.close();
}

TEST(PassengerFileManagerTestSuite, PassengerFileManager) {
    vector<Passenger*> attentionPassengers = PassengerFileManager::getInstance('c').getPassengers()->allObjects();

    EXPECT_TRUE(attentionPassengers.size() == 7);
}