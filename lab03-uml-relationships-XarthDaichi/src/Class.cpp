//
// Created by Xarthy on 0009 April 09, 2022.
//

#include "Class.h"

Class::Class() {}

Class::~Class() {

}

const std::string &Class::getCourse() const {
    return course;
}

void Class::setCourse(const std::string &course) {
    Class::course = course;
}

const Period &Class::getPeriod() const {
    return period;
}

void Class::setPeriod(const Period &period) {
    Class::period = period;
}

std::vector <Student> *Class::getStudents() const {
    return students;
}

void Class::setStudents(std::vector <Student> *students) {
    Class::students = students;
}

Teacher *Class::getTeacher() const {
    return teacher;
}

void Class::setTeacher(Teacher *teacher) {
    Class::teacher = teacher;
}

std::ostream &operator<<(std::ostream &os, const Class &aClass) {
    os << static_cast<const Object &>(aClass) << " course: " << aClass.course << " period: " << aClass.period
       << " students: " << aClass.students << " teacher: " << aClass.teacher;
    return os;
}
