//
// Created by Xarthy on 0009 April 09, 2022.
//

#ifndef LAB03_UML_RELATIONSHIPS_XARTHDAICHI_STUDENT_H
#define LAB03_UML_RELATIONSHIPS_XARTHDAICHI_STUDENT_H

#include <ostream>
#include "Human.h"
#include "Class.h"

class Student : public Human {
private:
    int year;
    int credits;
    bool scholarship;
    vector<Class> * classes;
public:
    Student();

    virtual ~Student();

    int getYear() const;

    void setYear(int year);

    int getCredits() const;

    void setCredits(int credits);

    bool isScholarship() const;

    void setScholarship(bool scholarship);

    vector <Class> *getClasses() const;

    void setClasses(vector <Class> *classes);

    friend std::ostream &operator<<(std::ostream &os, const Student &student);
};


#endif //LAB03_UML_RELATIONSHIPS_XARTHDAICHI_STUDENT_H
