//
// Created by Xarthy on 0009 April 09, 2022.
//

#include "Teacher.h"

Teacher::Teacher() {}

Teacher::~Teacher() {

}

std::vector <Class> *Teacher::getClasses() const {
    return classes;
}

void Teacher::setClasses(std::vector <Class> *classes) {
    Teacher::classes = classes;
}

std::ostream &operator<<(std::ostream &os, const Teacher &teacher) {
    os << static_cast<const Employee &>(teacher) << " classes: "
       << teacher.classes;
    return os;
}

float Teacher::calculateSalary() {
    return 0;
}
