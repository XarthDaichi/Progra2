//
// Created by Xarthy on 0020 March 20, 2022.
//

#include "FullTimeEmployee.h"

FullTimeEmployee::FullTimeEmployee() {}

FullTimeEmployee::FullTimeEmployee(const string &name, int age, int employeeId, int jobId, float paymentPerHour,
                                   const BankAccount &bankAccount, vector<Address> *addressList, int workingHours)
        : Employee(name, age, employeeId, jobId, paymentPerHour, bankAccount, addressList),
          workingHours(workingHours) {}

FullTimeEmployee::~FullTimeEmployee() {

}

int FullTimeEmployee::getWorkingHours() const {
    return workingHours;
}

void FullTimeEmployee::setWorkingHours(int workingHours) {
    FullTimeEmployee::workingHours = workingHours;
}

float FullTimeEmployee::calculateSalary() {
    return (workingHours * paymentPerHour) - (workingHours * paymentPerHour * 0.29);
}

string FullTimeEmployee::returnHomeAddress() const {
    for(Address i : *addressList) {
        if(i.getType() == "HOME") {
            return i.getAddress();
        }
    }
    return "No Home Address";
}

ostream &operator<<(ostream &os, const FullTimeEmployee &employee) {
    os << static_cast<const Employee &>(employee) << "  workingHours: " << employee.workingHours;
    return os;
}
