//
// Created by Xarthy on 0020 March 20, 2022.
//

#include "Employee.h"

Employee::Employee() {}

Employee::Employee(const string &name, int age, int employeeId, int jobId, float paymentPerHour,
                   const BankAccount &bankAccount, vector<Address> *addressList) : Person(name, age),
                                                                                   employeeId(employeeId), jobId(jobId),
                                                                                   paymentPerHour(paymentPerHour),
                                                                                   bankAccount(bankAccount),
                                                                                   addressList(addressList) {}

Employee::~Employee() {

}

int Employee::getEmployeeId() const {
    return employeeId;
}

void Employee::setEmployeeId(int employeeId) {
    Employee::employeeId = employeeId;
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

vector<Address> *Employee::getAddressList() const {
    return addressList;
}

void Employee::setAddressList(vector<Address> *addressList) {
    Employee::addressList = addressList;
}

ostream &operator<<(ostream &os, const Employee &employee) {
    os << static_cast<const Person &>(employee) << " employeeId: " << employee.employeeId << " jobId: "
       << employee.jobId << " paymentPerHour: " << employee.paymentPerHour << " bankAccount: " << employee.bankAccount
       << " addressList: ";
    for (Address i : *employee.addressList) {
        os << i << ' ';
    }
    return os;
}


