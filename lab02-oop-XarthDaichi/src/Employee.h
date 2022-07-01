//
// Created by Xarthy on 0020 March 20, 2022.
//

#ifndef CLASESABSTRACTASEINTERFACES_EMPLOYEE_H
#define CLASESABSTRACTASEINTERFACES_EMPLOYEE_H
#include <vector>
#include <ostream>
#include "Person.h"
#include "BankAccount.h"
#include "Address.h"


class Employee : public Person{
protected:
    int employeeId;
    int jobId;
    float paymentPerHour;
    BankAccount bankAccount;
    vector<Address> * addressList;
public:
    Employee();

    Employee(const string &name, int age, int employeeId, int jobId, float paymentPerHour,
             const BankAccount &bankAccount, vector<Address> *addressList);

    virtual ~Employee();

    int getEmployeeId() const;

    void setEmployeeId(int employeeId);

    int getJobId() const;

    void setJobId(int jobId);

    float getPaymentPerHour() const;

    void setPaymentPerHour(float paymentPerHour);

    const BankAccount &getBankAccount() const;

    void setBankAccount(const BankAccount &bankAccount);

    vector<Address> *getAddressList() const;

    void setAddressList(vector<Address> *addressList);

    virtual float calculateSalary() = 0;

    friend ostream &operator<<(ostream &os, const Employee &employee);
};


#endif //CLASESABSTRACTASEINTERFACES_EMPLOYEE_H
