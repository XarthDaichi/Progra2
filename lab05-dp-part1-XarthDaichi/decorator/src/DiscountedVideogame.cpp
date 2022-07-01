//
// Created by Xarthy on 0020 May 20, 2022.
//

#include "DiscountedVideogame.h"

DiscountedVideogame::DiscountedVideogame(const Videogame &videogame, double discount) : videogame(videogame),
                                                                                        discount(discount) {}

DiscountedVideogame::~DiscountedVideogame() {

}

const Videogame &DiscountedVideogame::getVideogame() const {
    return videogame;
}

double DiscountedVideogame::getDiscount() const {
    return discount;
}

void DiscountedVideogame::setDiscount(double discount) {
    DiscountedVideogame::discount = discount;
}

ostream &operator<<(ostream &os, const DiscountedVideogame &videogame) {
    os << videogame.videogame << " discount: " << videogame.discount << " discountPrice: " << (videogame.videogame.getPrice() * (1- videogame.discount));
    return os;
}
