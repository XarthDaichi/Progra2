//
// Created by Xarthy on 0009 April 09, 2022.
//

#ifndef LAB03_UML_RELATIONSHIPS_XARTHDAICHI_TEACHER_H
#define LAB03_UML_RELATIONSHIPS_XARTHDAICHI_TEACHER_H

#include <ostream>
#include "Employee.h"
#include "Class.h"
#include "Salary.h"

class Teacher : public Employee, public Salary {
private:
    vector<Class> * classes;
public:
    Teacher();

    virtual ~Teacher();

    vector <Class> *getClasses() const;

    void setClasses(vector <Class> *classes);

    friend std::ostream &operator<<(std::ostream &os, const Teacher &teacher);

    float calculateSalary() override;
};


#endif //LAB03_UML_RELATIONSHIPS_XARTHDAICHI_TEACHER_H
