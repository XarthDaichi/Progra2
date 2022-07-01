//
// Created by Xarthy on 0020 March 20, 2022.
//

#include "Address.h"

Address::Address() {}

Address::~Address() {

}

const string &Address::getType() const {
    return type;
}

void Address::setType(const string &type) {
    Address::type = type;
}

const string &Address::getAddress() const {
    return address;
}

void Address::setAddress(const string &address) {
    Address::address = address;
}

ostream &operator<<(ostream &os, const Address &address) {
    os << "type: " << address.type << ", address: " << address.address;
    return os;
}
