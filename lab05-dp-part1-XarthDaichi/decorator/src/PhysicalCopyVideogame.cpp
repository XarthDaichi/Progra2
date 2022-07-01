//
// Created by Xarthy on 0020 May 20, 2022.
//

#include "PhysicalCopyVideogame.h"

PhysicalCopyVideogame::PhysicalCopyVideogame() {}

PhysicalCopyVideogame::PhysicalCopyVideogame(const string &name, const string &company, double price,
                                             const string &seller) : Videogame(name, company, price), seller(seller) {}

const string &PhysicalCopyVideogame::getSeller() const {
    return seller;
}

void PhysicalCopyVideogame::setSeller(const string &seller) {
    PhysicalCopyVideogame::seller = seller;
}

ostream &operator<<(ostream &os, const PhysicalCopyVideogame &videogame) {
    os << static_cast<const Videogame &>(videogame) << " seller: " << videogame.seller;
    return os;
}
