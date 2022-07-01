//
// Created by Xarthy on 0020 March 20, 2022.
//

#ifndef CLASESABSTRACTASEINTERFACES_CONTRACTOR_H
#define CLASESABSTRACTASEINTERFACES_CONTRACTOR_H
#include "Employee.h"
#include "IWorkingFromHome.h"
#include "IWorkingFromOffice.h"

class Contractor : public Employee, public IWorkingFromOffice, public IWorkingFromHome {
private:
    int fixedHours;
public:
    Contractor(const string &name, int age, int emploeeId, int jobId, float paymentPerHour,
               const BankAccount &bankAccount, Address **addressList, int fixedHours);

    virtual ~Contractor();

    int getFixedHours() const;

    void setFixedHours(int fixedHours);

    virtual float calculateSalary();

    string returnOfficeAddress() const;

    string returnHomeAddress() const;
};


#endif //CLASESABSTRACTASEINTERFACES_CONTRACTOR_H
