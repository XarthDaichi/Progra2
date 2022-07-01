//
// Created by Xarthy on 0020 April 20, 2022.
//

#ifndef LAB04_V2_DATAFLOW_XARTHDAICHI_PERSON_H
#define LAB04_V2_DATAFLOW_XARTHDAICHI_PERSON_H

#include <ostream>
#include "Object.h"

class Person : public Object {
private:
    std::string firstName;
    std::string lastName;
    int id;
    std::string email;
public:
    Person();

    Person(const std::string &firstName, const std::string &lastName, int id, const std::string &email);

    virtual ~Person();

    const std::string &getFirstName() const;

    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    int getId() const;

    void setId(int id);

    const std::string &getEmail() const;

    void setEmail(const std::string &email);

    friend std::ostream &operator<<(std::ostream &os, const Person &person);

    std::string toString() const override;
};


#endif //LAB04_V2_DATAFLOW_XARTHDAICHI_PERSON_H
