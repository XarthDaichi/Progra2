//
// Created by Xarthy on 0020 March 20, 2022.
//

#include "Address.h"

Address::Address(const string &type, const string &address) : type(type), address(address) {}

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
