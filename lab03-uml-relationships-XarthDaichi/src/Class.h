//
// Created by Xarthy on 0009 April 09, 2022.
//

#ifndef LAB03_UML_RELATIONSHIPS_XARTHDAICHI_CLASS_H
#define LAB03_UML_RELATIONSHIPS_XARTHDAICHI_CLASS_H

#include <ostream>
#include "Object.h"
#include "Period.h"
#include "Teacher.h"
#include "Student.h"

class Class : public Object {
private:
    std::string course;
    Period period;
    vector<Student> * students;
    Teacher * teacher;
public:
    Class();

    virtual ~Class();

    const std::string &getCourse() const;

    void setCourse(const std::string &course);

    const Period &getPeriod() const;

    void setPeriod(const Period &period);

    vector <Student> *getStudents() const;

    void setStudents(vector <Student> *students);

    Teacher *getTeacher() const;

    void setTeacher(Teacher *teacher);

    friend std::ostream &operator<<(std::ostream &os, const Class &aClass);
};


#endif //LAB03_UML_RELATIONSHIPS_XARTHDAICHI_CLASS_H
