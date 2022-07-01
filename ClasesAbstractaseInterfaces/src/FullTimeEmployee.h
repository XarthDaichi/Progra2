//
// Created by Xarthy on 0020 March 20, 2022.
//

#ifndef CLASESABSTRACTASEINTERFACES_FULLTIMEEMPLOYEE_H
#define CLASESABSTRACTASEINTERFACES_FULLTIMEEMPLOYEE_H
#include "Employee.h"
#include "IworkingFromHome.h"

class FullTimeEmployee : public Employee, public IWorkingFromHome {
private:
    int workingHours;
public:
    FullTimeEmployee(const string &name, int age, int emploeeId, int jobId, float paymentPerHour,
                     const BankAccount &bankAccount, Address **addressList, int workingHours);

    virtual ~FullTimeEmployee();

    int getWorkingHours() const;

    void setWorkingHours(int workingHours);

    virtual float calculateSalary();

    string returnHomeAddress() const;
};


#endif //CLASESABSTRACTASEINTERFACES_FULLTIMEEMPLOYEE_H
