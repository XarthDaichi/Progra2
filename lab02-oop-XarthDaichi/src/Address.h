//
// Created by Xarthy on 0020 March 20, 2022.
//

#ifndef CLASESABSTRACTASEINTERFACES_ADDRESS_H
#define CLASESABSTRACTASEINTERFACES_ADDRESS_H
#include <iostream>
using namespace std;

class Address {
private:
    string type;
    string address;
public:
    Address();

    Address(const string &type, const string &address);

    virtual ~Address();

    const string &getType() const;

    void setType(const string &type);

    const string &getAddress() const;

    void setAddress(const string &address);

    friend ostream &operator<<(ostream &os, const Address &address);
};


#endif //CLASESABSTRACTASEINTERFACES_ADDRESS_H
