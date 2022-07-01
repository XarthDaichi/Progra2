//
// Created by Xarthy on 0020 March 20, 2022.
//

#include "Employee.h"
Employee::Employee(const string &name, int age, int emploeeId, int jobId, float paymentPerHour,
                   const BankAccount &bankAccount, Address **addressList) : Person(name, age), emploeeId(emploeeId),
                                                                            jobId(jobId),
                                                                            paymentPerHour(paymentPerHour),
                                                                            bankAccount(bankAccount),
                                                                            addressList(addressList) {}

Employee::~Employee() {

}

int Employee::getEmploeeId() const {
    return emploeeId;
}

void Employee::setEmploeeId(int emploeeId) {
    Employee::emploeeId = emploeeId;
}

int Employee::getJobId() const {
    return jobId;
}

void Employee::setJobId(int jobId) {
    Employee::jobId = jobId;
}

float Employee::getPaymentPerHour() const {
    return paymentPerHour;
}

void Employee::setPaymentPerHour(float paymentPerHour) {
    Employee::paymentPerHour = paymentPerHour;
}

const BankAccount &Employee::getBankAccount() const {
    return bankAccount;
}

void Employee::setBankAccount(const BankAccount &bankAccount) {
    Employee::bankAccount = bankAccount;
}

Address **Employee::getAddressList() const {
    return addressList;
}

void Employee::setAddressList(Address **addressList) {
    Employee::addressList = addressList;
}