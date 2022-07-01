//
// Created by Xarthy on 0016 June 16, 2022.
//

#include "Clothing.h"

Clothing::Clothing() = default;

Clothing::Clothing(const string &code) : code(code) { price = 0;}

Clothing::~Clothing() = default;

double Clothing::getPrice() const {
    return price;
}

void Clothing::setPrice(double price) {
    Clothing::price = price;
}

const string &Clothing::getCode() const {
    return code;
}

void Clothing::setCode(const string &code) {
    Clothing::code = code;
}

void Clothing::add(Clothing *clothing) {

}

void Clothing::remove(Clothing *clothing) {

}

ostream &operator<<(ostream &os, const Clothing &clothing) {
    os << " code: " << clothing.code << " price: " << clothing.price ;
    return os;
}
