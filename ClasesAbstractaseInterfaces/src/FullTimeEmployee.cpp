//
// Created by Xarthy on 0020 March 20, 2022.
//

#include "FullTimeEmployee.h"

FullTimeEmployee::FullTimeEmployee(const string &name, int age, int emploeeId, int jobId, float paymentPerHour,
                                   const BankAccount &bankAccount, Address **addressList, int workingHours) : Employee(
        name, age, emploeeId, jobId, paymentPerHour, bankAccount, addressList), workingHours(workingHours) {}

FullTimeEmployee::~FullTimeEmployee() {

}

int FullTimeEmployee::getWorkingHours() const {
    return workingHours;
}

void FullTimeEmployee::setWorkingHours(int workingHours) {
    FullTimeEmployee::workingHours = workingHours;
}

float calculateSalary() {
    return 0;
}

string returnHomeAddress() const {
    return "HomeAddress";
}
