//
// Created by Xarthy on 0009 April 09, 2022.
//

#include "Employee.h"

Employee::Employee() {}

Employee::~Employee() {

}

int Employee::getEmployeeId() const {
    return employeeId;
}

void Employee::setEmployeeId(int employeeId) {
    Employee::employeeId = employeeId;
}

int Employee::getHoursWorked() const {
    return hoursWorked;
}

void Employee::setHoursWorked(int hoursWorked) {
    Employee::hoursWorked = hoursWorked;
}

std::ostream &operator<<(std::ostream &os, const Employee &employee) {
    os << static_cast<const Human &>(employee) << " employeeId: " << employee.employeeId << " hoursWorked: "
       << employee.hoursWorked;
    return os;
}
