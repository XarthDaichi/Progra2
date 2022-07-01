//
// Created by ribre on 21/06/2022.
//

#include "Company.h"

Company::Company(const string &name, const string &id, int countryCode, bool online, bool startup)
        : Subscriber(name, id, 400, countryCode, online), startup(startup) {}

Company::Company(bool startup) : startup(startup) {
    Company::subPay = 400;
}

bool Company::isStartup() const {
    return startup;
}

void Company::setStartup(bool startup) {
    Company::startup = startup;
}

double Company::getSubPay() {
    return subPay;
}

ostream &operator<<(ostream &os, const Company &company) {
    if(company.isOnline()) {
        os << static_cast<const Subscriber &>(company) << " startup: " << company.startup
           << " Coste de envio: " << company.getSendCost()
           << " dolares, Ciudad: " << company.getCity()
           << " Pais: " << company.getCountry()
           << " Coste de sustripcion: " << company.subPay;
    }
    else {
        os << static_cast<const Subscriber &>(company) << " startup: " << company.startup;
    }
    return os;
}

string Company::toString() {
    std::stringstream s;
    s << (*this);
    return s.str();
}

Company::~Company() = default;
