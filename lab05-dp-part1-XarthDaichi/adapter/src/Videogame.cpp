//
// Created by Xarthy on 0019 May 19, 2022.
//

#include "Videogame.h"

Videogame::Videogame() {}

Videogame::Videogame(double priceDollar, const string &name, const string &company) : priceDollar(priceDollar),
                                                                                      name(name), company(company) {}

Videogame::~Videogame() {

}

double Videogame::getPriceDollar() const {
    return priceDollar;
}

void Videogame::setPriceDollar(double priceDollar) {
    Videogame::priceDollar = priceDollar;
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

ostream &operator<<(ostream &os, const Videogame &videogame) {
    os << "name: " << videogame.name << " company: " << videogame.company << " priceDollar: " << videogame.priceDollar;
    return os;
}
