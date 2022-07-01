//
// Created by Maikol Guzman Alan on 3/19/22.
// https://google.github.io/googletest/reference/assertions.html
//

#include <FullTimeEmployee.h>
#include "gtest/gtest.h"

/**
 * This test check the calculate salary
 */
TEST(FullTimeEmployeeTestSuite, CalculateSalary) {

    FullTimeEmployee fullTimeEmployee;
    fullTimeEmployee.setPaymentPerHour(25);
    fullTimeEmployee.setWorkingHours(8);

    // Assert ASSERT_EQ o compare two string objects
    ASSERT_EQ(fullTimeEmployee.calculateSalary(),142);
}

/**
 * Check the return home address
 */
TEST(FullTimeEmployeeTestSuite, CheckHomeAddress) {
    Address addressHome;
    addressHome.setType("HOME");
    addressHome.setAddress("San José, Costa Rica");

    vector<Address> addressList;
    addressList.push_back(addressHome);

    FullTimeEmployee fullTimeEmployee;
    fullTimeEmployee.setAddressList(&addressList);

    // Assert EXPECT_STREQ The following assertions compare two C strings.
    EXPECT_STREQ(fullTimeEmployee.returnHomeAddress().c_str(),"San José, Costa Rica");
}

/**
 * Check the content of the object
 */
TEST(FullTimeEmployeeTestSuite, CheckObjectContent) {
    BankAccount bankAccount;
    bankAccount.setBankNumber(111111);

    Address addressHome;
    addressHome.setType("HOME");
    addressHome.setAddress("San José, Costa Rica");

    Address addressOffice;
    addressOffice.setType("OFFICE");
    addressOffice.setAddress("Heredia, Costa Rica");

    vector<Address> addressList;
    addressList.push_back(addressOffice);
    addressList.push_back(addressHome);

    FullTimeEmployee fullTimeEmployee;
    fullTimeEmployee.setName("Pedro Gonzales");
    fullTimeEmployee.setAge(25);
    fullTimeEmployee.setEmployeeId(12345);
    fullTimeEmployee.setJobId(123);
    fullTimeEmployee.setPaymentPerHour(25);
    fullTimeEmployee.setBankAccount(bankAccount);
    fullTimeEmployee.setAddressList(&addressList);
    fullTimeEmployee.setWorkingHours(8);

    // Convert from ostream to ostringstream
    ostringstream objectData;
    objectData << fullTimeEmployee;

    // Assert EXPECT_STREQ The following assertions compare two C strings.
    EXPECT_STREQ(objectData.str().c_str(),"name: Pedro Gonzales age: 25 employeeId: 12345 "
                                          "jobId: 123 paymentPerHour: 25 bankAccount: bankNumber: 111111 "
                                          "addressList: type: OFFICE, address: Heredia, Costa Rica type: HOME, "
                                          "address: San José, Costa Rica   workingHours: 8");

}
