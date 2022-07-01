//
// Created by Xarthy on 0009 April 09, 2022.
//

#ifndef LAB03_UML_RELATIONSHIPS_XARTHDAICHI_HUMAN_H
#define LAB03_UML_RELATIONSHIPS_XARTHDAICHI_HUMAN_H

#include <ostream>
#include "Object.h"

class Human : public Object {
protected:
    std::string name;
    int age;
    int id;
public:
    Human();

    virtual ~Human();

    const std::string &getName() const;

    void setName(const std::string &name);

    int getAge() const;

    void setAge(int age);

    int getId() const;

    void setId(int id);

    friend std::ostream &operator<<(std::ostream &os, const Human &human);
};


#endif //LAB03_UML_RELATIONSHIPS_XARTHDAICHI_HUMAN_H
