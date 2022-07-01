//
// Created by Xarthy on 0021 May 21, 2022.
//

#include "Videogame.h"

Videogame::Videogame() {}

Videogame::Videogame(const string &name, const string &company, double price) : name(name), company(company),
                                                                                price(price) {}

Videogame::~Videogame() {

}

const string &Videogame::getName() const {
    return name;
}

void Videogame::setName(const string &name) {
    Videogame::name = name;
}

const string &Videogame::getCompany() const {
    return company;
}

void Videogame::setCompany(const string &company) {
    Videogame::company = company;
}

double Videogame::getPrice() const {
    return price;
}

void Videogame::setPrice(double price) {
    Videogame::price = price;
}

ostream &operator<<(ostream &os, const Videogame &videogame) {
    os << "name: " << videogame.name << " company: " << videogame.company << " price: " << videogame.price;
    return os;
}
