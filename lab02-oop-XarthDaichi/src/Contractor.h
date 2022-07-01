//
// Created by Xarthy on 0020 March 20, 2022.
//

#ifndef CLASESABSTRACTASEINTERFACES_CONTRACTOR_H
#define CLASESABSTRACTASEINTERFACES_CONTRACTOR_H

#include <ostream>
#include "Employee.h"
#include "IWorkingFromHome.h"
#include "IWorkingFromOffice.h"

class Contractor : public Employee, public IWorkingFromOffice, public IWorkingFromHome {
private:
    int fixedHours;
public:
    Contractor();

    Contractor(const string &name, int age, int employeeId, int jobId, float paymentPerHour,
               const BankAccount &bankAccount, vector<Address> *addressList, int fixedHours);

    virtual ~Contractor();

    int getFixedHours() const;

    void setFixedHours(int fixedHours);

    float calculateSalary() override;

    string returnOfficeAddress() const override;

    string returnHomeAddress() const override;

    friend ostream &operator<<(ostream &os, const Contractor &contractor);
};


#endif //CLASESABSTRACTASEINTERFACES_CONTRACTOR_H
