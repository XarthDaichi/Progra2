//
// Created by Xarthy on 0020 March 20, 2022.
//

#ifndef CLASESABSTRACTASEINTERFACES_EMPLOYEE_H
#define CLASESABSTRACTASEINTERFACES_EMPLOYEE_H
#include "Person.h"
#include "BankAccount.h"
#include "Address.h"


class Employee : public Person{
protected:
    int emploeeId;
    int jobId;
    float paymentPerHour;
    BankAccount bankAccount;
    Address** addressList; // std::vector<Address*> addressList;
public:
    Employee(const string &name, int age, int emploeeId, int jobId, float paymentPerHour,
             const BankAccount &bankAccount, Address **addressList);

    virtual ~Employee();

    int getEmploeeId() const;

    void setEmploeeId(int emploeeId);

    int getJobId() const;

    void setJobId(int jobId);

    float getPaymentPerHour() const;

    void setPaymentPerHour(float paymentPerHour);

    const BankAccount &getBankAccount() const;

    void setBankAccount(const BankAccount &bankAccount);

    Address **getAddressList() const;

    void setAddressList(Address **addressList);

    virtual float calculateSalary() = 0;
};


#endif //CLASESABSTRACTASEINTERFACES_EMPLOYEE_H
