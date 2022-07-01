//
// Created by Xarthy on 0020 May 20, 2022.
//

#include "DigitalCopyVideogame.h"

DigitalCopyVideogame::DigitalCopyVideogame() {}

DigitalCopyVideogame::DigitalCopyVideogame(const string &name, const string &company, double price,
                                           const string &onlineRetailer) : Videogame(name, company, price),
                                                                           onlineRetailer(onlineRetailer) {}

DigitalCopyVideogame::~DigitalCopyVideogame() {

}

const string &DigitalCopyVideogame::getOnlineRetailer() const {
    return onlineRetailer;
}

void DigitalCopyVideogame::setOnlineRetailer(const string &onlineRetailer) {
    DigitalCopyVideogame::onlineRetailer = onlineRetailer;
}

ostream &operator<<(ostream &os, const DigitalCopyVideogame &videogame) {
    os << static_cast<const Videogame &>(videogame) << " onlineRetailer: " << videogame.onlineRetailer;
    return os;
}
