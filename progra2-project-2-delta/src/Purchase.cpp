//
// Created by Xarthy on 0022 June 22, 2022.
//

#include "Purchase.h"

Purchase::Purchase() = default;

Purchase::Purchase(Set *cart, Subscriber *buyer) : cart(cart), buyer(buyer) {}

Purchase::~Purchase() = default;

Set *Purchase::getCart() const {
    return cart;
}

void Purchase::setCart(Set *cart) {
    Purchase::cart = cart;
}

Subscriber *Purchase::getBuyer() const {
    return buyer;
}

void Purchase::setBuyer(Subscriber *buyer) {
    Purchase::buyer = buyer;
}

ostream &operator<<(ostream &os, const Purchase &purchase) {
    os << "buyer: " << *purchase.buyer << " cart: " << *purchase.cart ;
    return os;
}

string Purchase::toString() const {
    stringstream s;
    s << *this;
    return s.str();
}
