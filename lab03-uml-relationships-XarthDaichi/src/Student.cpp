//
// Created by Xarthy on 0009 April 09, 2022.
//

#include "Student.h"

Student::Student() {}

Student::~Student() {

}

int Student::getYear() const {
    return year;
}

void Student::setYear(int year) {
    Student::year = year;
}

int Student::getCredits() const {
    return credits;
}

void Student::setCredits(int credits) {
    Student::credits = credits;
}

bool Student::isScholarship() const {
    return scholarship;
}

void Student::setScholarship(bool scholarship) {
    Student::scholarship = scholarship;
}

std::vector <Class> *Student::getClasses() const {
    return classes;
}

void Student::setClasses(std::vector<Class> *classes) {
    Student::classes = classes;
}

std::ostream &operator<<(std::ostream &os, const Student &student) {
    os << static_cast<const Human &>(student) << " year: " << student.year << " credits: " << student.credits
       << " scholarship: " << student.scholarship << " classes: " << student.classes;
    return os;
}
