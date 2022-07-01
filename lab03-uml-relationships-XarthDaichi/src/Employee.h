//
// Created by Xarthy on 0009 April 09, 2022.
//

#ifndef LAB03_UML_RELATIONSHIPS_XARTHDAICHI_EMPLOYEE_H
#define LAB03_UML_RELATIONSHIPS_XARTHDAICHI_EMPLOYEE_H

#include <ostream>
#include "Human.h"

class Employee : public Human{
protected:
    int employeeId;
    int hoursWorked;
public:
    Employee();

    virtual ~Employee();

    int getEmployeeId() const;

    void setEmployeeId(int employeeId);

    int getHoursWorked() const;

    void setHoursWorked(int hoursWorked);

    friend std::ostream &operator<<(std::ostream &os, const Employee &employee);
};


#endif //LAB03_UML_RELATIONSHIPS_XARTHDAICHI_EMPLOYEE_H
