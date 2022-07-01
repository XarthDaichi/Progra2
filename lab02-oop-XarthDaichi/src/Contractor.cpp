//
// Created by Xarthy on 0020 March 20, 2022.
//

#include "Contractor.h"

Contractor::Contractor() {}

Contractor::Contractor(const string &name, int age, int employeeId, int jobId, float paymentPerHour,
                       const BankAccount &bankAccount, vector<Address> *addressList, int fixedHours) : Employee(name,
                                                                                                                age,
                                                                                                                employeeId,
                                                                                                                jobId,
                                                                                                                paymentPerHour,
                                                                                                                bankAccount,
                                                                                                                addressList),
                                                                                                       fixedHours(
                                                                                                               fixedHours) {}

Contractor::~Contractor() {

}

int Contractor::getFixedHours() const {
    return fixedHours;
}

void Contractor::setFixedHours(int fixedHours) {
    Contractor::fixedHours = fixedHours;
}

float Contractor::calculateSalary() {
    return fixedHours * paymentPerHour;
}

string Contractor::returnOfficeAddress() const {
    for(Address i : *addressList) {
        if(i.getType() == "OFFICE") {
            return i.getAddress();
        }
    }
    return "No Office Address";
}

string Contractor::returnHomeAddress() const {
    for(Address i : *addressList) {
        if(i.getType() == "HOME") {
            return i.getAddress();
        }
    }
    return "No Home Address";
}

ostream &operator<<(ostream &os, const Contractor &contractor) {
    os << static_cast<const Employee &>(contractor); //<< " fixedHours: " << contractor.fixedHours;
    return os;
}
