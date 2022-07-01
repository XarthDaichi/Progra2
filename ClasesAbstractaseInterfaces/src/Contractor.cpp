//
// Created by Xarthy on 0020 March 20, 2022.
//

#include "Contractor.h"

Contractor::Contractor(const string &name, int age, int emploeeId, int jobId, float paymentPerHour,
                       const BankAccount &bankAccount, Address **addressList, int fixedHours) : Employee(name, age,
                                                                                                         emploeeId,
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
    return 0;
}

string returnOfficeAddress() const {
    return "OfficeAddress";
}

string returnHomeAddress() const {
    return "HomeAddress";
}
