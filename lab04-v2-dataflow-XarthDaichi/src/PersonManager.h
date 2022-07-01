//
// Created by Xarthy on 0020 April 20, 2022.
//

#ifndef LAB04_V2_DATAFLOW_XARTHDAICHI_PERSONMANAGER_H
#define LAB04_V2_DATAFLOW_XARTHDAICHI_PERSONMANAGER_H
#include "Person.h"
#include "Utils.h"
#include <vector>
#include <ostream>

class PersonManager {
private:
    std::vector<Person> people;
public:
    PersonManager();

    explicit PersonManager(const std::vector<Person> &people);

    virtual ~PersonManager();

    const std::vector<Person> &getPeople() const;

    void setPeople(const std::vector<Person> &people);

    void addPerson(const Person &person);

    void removeLastPerson();

    friend std::ostream &operator<<(std::ostream &os, const PersonManager &manager);

    std::string toString() const;
};


#endif //LAB04_V2_DATAFLOW_XARTHDAICHI_PERSONMANAGER_H
