//
// Created by Xarthy on 0020 March 20, 2022.
//

#include "Contractor.h"
#include "FullTimeEmployee.h"

int main() {
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

    cout << fullTimeEmployee << endl;

    BankAccount bankAccount2;
    bankAccount2.setBankNumber(111111);

    Address addressHome2;
    addressHome2.setType("HOME");
    addressHome2.setAddress("San José, Costa Rica");

    Address addressOffice2;
    addressOffice2.setType("OFFICE");
    addressOffice2.setAddress("Heredia, Costa Rica");

    vector<Address> addressList2;
    addressList2.push_back(addressOffice2);
    addressList2.push_back(addressHome2);

    Contractor contractor;
    contractor.setName("Ana Ramirez");
    contractor.setAge(30);
    contractor.setEmployeeId(65489);
    contractor.setJobId(789);
    contractor.setPaymentPerHour(15);
    contractor.setBankAccount(bankAccount2);
    contractor.setAddressList(&addressList2);
    contractor.setFixedHours(200);
    cout << contractor << endl;
//    "name: Ana Ramirez age: 30 employeeId: 65489 jobId: 789 "
//    "paymentPerHour: 15 bankAccount: bankNumber: 111111 "
//    "addressList: type: OFFICE, address: Heredia, Costa Rica type: HOME, "
//    "address: San José, Costa Rica "
    return 0;
}
