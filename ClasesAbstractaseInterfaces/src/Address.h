//
// Created by Xarthy on 0020 March 20, 2022.
//

#ifndef CLASESABSTRACTASEINTERFACES_ADDRESS_H
#define CLASESABSTRACTASEINTERFACES_ADDRESS_H
#include <iostream>

class Address {
private:
    string type;
    string address;
public:
    Address(const string &type, const string &address);

    virtual ~Address();

    const string &getType() const;

    void setType(const string &type);

    const string &getAddress() const;

    void setAddress(const string &address);
};


#endif //CLASESABSTRACTASEINTERFACES_ADDRESS_H
