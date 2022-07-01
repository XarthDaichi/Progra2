//
// Created by Xarthy on 0016 June 16, 2022.
//

#include "Garment.h"

Garment::Garment() {}

Garment::Garment(const string &code, const string &color, const string &size, const string &type,
                 bool characteristic) : Clothing(code), color(color), size(size), type(type),
                                        characteristic(characteristic) {
    price = calculatePrice();
}

Garment::~Garment() = default;

const string &Garment::getColor() const {
    return color;
}

void Garment::setColor(const string &color) {
    Garment::color = color;
}

const string &Garment::getSize() const {
    return size;
}

void Garment::setSize(const string &size) {
    Garment::size = size;
    price = calculatePrice();
}

const string &Garment::getType() const {
    return type;
}

void Garment::setType(const string &type) {
    Garment::type = type;
    price = calculatePrice();
}

bool Garment::isCharacteristic() const {
    return characteristic;
}

void Garment::setCharacteristic(bool characteristic) {
    Garment::characteristic = characteristic;
    price = calculatePrice();
}

ostream &operator<<(ostream &os, const Garment &garment) {
    os << static_cast<const Clothing &>(garment) << " color: " << garment.color << " size: " << garment.size
       << " type: " << garment.type << " characteristic: " << garment.characteristic;
    return os;
}

string Garment::toString() const {
    stringstream s;
    s << (*this);
    return s.str();
}

vector<Clothing *> Garment::hasClothes() const {
    return vector<Clothing *>();
}

double Garment::calculatePrice() const {
    return PricingManager::itemPrice(type, characteristic, size);
}
