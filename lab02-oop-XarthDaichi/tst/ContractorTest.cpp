//
// Created by Maikol Guzman Alan on 3/19/22.
//
#include <Contractor.h>
#include "gtest/gtest.h"

/**
 * This test check the calculate salary
 */
TEST(ContractorTestSuite, CalculateSalary) {
    Contractor contractor;

    contractor.setPaymentPerHour(15);
    contractor.setFixedHours(200);

    // Assert ASSERT_EQ o compare two string objects
    ASSERT_EQ(contractor.calculateSalary(),3000);
}

/**
 * Check the return home address
 */
TEST(ContractorTestSuite, CheckAddressList) {
    Address addressHome;
    addressHome.setType("HOME");
    addressHome.setAddress("San José, Costa Rica");

    Address addressOffice;
    addressOffice.setType("OFFICE");
    addressOffice.setAddress("Heredia, Costa Rica");

    vector<Address> addressList;
    addressList.push_back(addressHome);
    addressList.push_back(addressOffice);

    Contractor contractor;
    contractor.setAddressList(&addressList);

    // Assert EXPECT_STREQ The following assertions compare two C strings.
    EXPECT_STREQ(contractor.returnHomeAddress().c_str(),"San José, Costa Rica");
    EXPECT_STREQ(contractor.returnOfficeAddress().c_str(),"Heredia, Costa Rica");
}


/**
 * Check the content of the object
 */
TEST(ContractorTestSuite, CheckObjectContent) {
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

    Contractor contractor;
    contractor.setName("Ana Ramirez");
    contractor.setAge(30);
    contractor.setEmployeeId(65489);
    contractor.setJobId(789);
    contractor.setPaymentPerHour(15);
    contractor.setBankAccount(bankAccount);
    contractor.setAddressList(&addressList);
    contractor.setFixedHours(200);

    // Convert from ostream to ostringstream
    ostringstream objectData;
    objectData << contractor;

    // Assert EXPECT_STREQ The following assertions compare two C strings.
    EXPECT_STREQ(objectData.str().c_str(),"name: Ana Ramirez age: 30 employeeId: 65489 jobId: 789 "
                                          "paymentPerHour: 15 bankAccount: bankNumber: 111111 "
                                          "addressList: type: OFFICE, address: Heredia, Costa Rica type: HOME, "
                                          "address: San José, Costa Rica ");

}