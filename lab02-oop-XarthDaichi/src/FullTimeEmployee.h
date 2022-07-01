//
// Created by Xarthy on 0020 March 20, 2022.
//

#ifndef CLASESABSTRACTASEINTERFACES_FULLTIMEEMPLOYEE_H
#define CLASESABSTRACTASEINTERFACES_FULLTIMEEMPLOYEE_H

#include <ostream>
#include "Employee.h"
#include "IworkingFromHome.h"

class FullTimeEmployee : public Employee, public IWorkingFromHome {
private:
    int workingHours;
public:
    FullTimeEmployee();

    FullTimeEmployee(const string &name, int age, int employeeId, int jobId, float paymentPerHour,
                     const BankAccount &bankAccount, vector<Address> *addressList, int workingHours);

    virtual ~FullTimeEmployee();

    int getWorkingHours() const;

    void setWorkingHours(int workingHours);

    float calculateSalary() override;

    string returnHomeAddress() const override;

    friend ostream &operator<<(ostream &os, const FullTimeEmployee &employee);
};


#endif //CLASESABSTRACTASEINTERFACES_FULLTIMEEMPLOYEE_H
