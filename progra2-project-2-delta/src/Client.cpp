//
// Created by ribre on 15/06/2022.
//
#include "Client.h"

Client::Client(){
    Client::subPay = 200;
}

Client::Client(const string &name, const string &id, int countryCode, bool online, const string &email)
        : Subscriber(name, id, 200, countryCode, online), email(email) {}

Client::~Client() = default;

const string &Client::getEmail() const {
    return email;
}

void Client::setEmail(const string &email) {
    Client::email = email;
}

double Client::getSubPay() {
    return subPay;
}

ostream &operator<<(ostream &os, const Client &client) {
    if(client.isOnline()) {
        os << static_cast<const Subscriber &>(client) << " email: " << client.email
           << " Coste de envio: " << client.getSendCost() << " dolares, Ciudad: "
           << client.getCity() << " Pais: " << client.getCountry() << " Coste de suscripcion: " << client.subPay;
    }
    else{
        os << static_cast<const Subscriber &>(client) << " email: " << client.email;
    }
    return os;
}

string Client::toString() {
    std::stringstream s;
    s << (*this);
    return s.str();
}
