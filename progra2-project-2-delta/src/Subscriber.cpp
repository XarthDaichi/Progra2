//
// Created by ribre on 21/06/2022.
//

#include "Subscriber.h"

#include <utility>

Subscriber::Subscriber(){
}

Subscriber::Subscriber(const string &name, const string &id, double subPay, int countryCode, bool online) : name(name), id(id), subPay(subPay),
                                                                              countryCode(countryCode),
                                                                              online(online) {
    sendCost = PricingManager::getShippingCost(countryCode);
    city = PricingManager::getCity(countryCode);
    country = PricingManager::getCountry(countryCode);
}

Subscriber::~Subscriber() = default;

const string &Subscriber::getName() const {
    return name;
}

void Subscriber::setName(const string &name) {
    Subscriber::name = name;
}

const string &Subscriber::getId() const {
    return id;
}

void Subscriber::setId(const string &id) {
    Subscriber::id = id;
}

bool Subscriber::isOnline() const {
    return online;
}

void Subscriber::setOnline(bool online) {
    Subscriber::online = online;
}

ostream &operator<<(ostream &os, const Subscriber &subscriber) {
    os << " name: " << subscriber.name << " id: " << subscriber.id;
    return os;
}

string Subscriber::toString() {
    std::stringstream s;
    s << (*this);
    return s.str();
}

void Subscriber::update(Set *stock, Set * catalog) {
    cout << "---Subscriber (" << id << ") Data---"
         << "--- Catalog ---" << endl
         << *catalog << endl
         << "--- Stock ---" << endl
         << *stock << endl;
}

int Subscriber::getCountryCode() const {
    return countryCode;
}

void Subscriber::setCountryCode(int countryCode) {
    Subscriber::countryCode = countryCode;

    Subscriber::sendCost = PricingManager::getShippingCost(countryCode);
    Subscriber::city = PricingManager::getCity(countryCode);
    Subscriber::country = PricingManager::getCountry(countryCode);
}

double Subscriber::getSendCost() const {
    return sendCost;
}

void Subscriber::setSendCost(double sendCost) {
    Subscriber::sendCost = sendCost;
}

const string &Subscriber::getCountry() const {
    return country;
}

void Subscriber::setCountry(const string &country) {
    Subscriber::country = country;
}

const string &Subscriber::getCity() const {
    return city;
}

void Subscriber::setCity(const string &city) {
    Subscriber::city = city;
}

double Subscriber::getSubPay() {
    return subPay;
}


