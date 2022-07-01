//
// Created by Xarthy on 0016 June 16, 2022.
//

#include "Set.h"

Set::Set() = default;

Set::Set(const string &code, const vector<Clothing *> &has) : Clothing(code), has(has) {
    price = Set::calculatePrice();
}

Set::~Set() = default;

void Set::setHas(const vector<Clothing *> &has) {
    Set::has = has;
    price = calculatePrice();
}

ostream &operator<<(ostream &os, const Set &set) {
    os << static_cast<const Clothing &>(set) << " has: ";
    for (auto * i : set.has) {
        Suit * iSuit = dynamic_cast<Suit *> (&*i);
        if (iSuit) os << *iSuit << " - ";
        else {
            Garment* iGar = dynamic_cast<Garment *> (&*i);
            if (iGar) os << *iGar << " - ";
        }
    }
    return os;
}

string Set::toString() const {
    stringstream s;
    s << (*this);
    return s.str();
}

void Set::add(Clothing *clothing) {
    has.push_back(clothing);
    price = calculatePrice();
}

void Set::remove(Clothing *clothing) {
    if(has.empty()) throw std::out_of_range("Set::remove: empty vector (has)");
    auto it = has.begin();
    for(int i = 0; i < has.size(); i++) {
        if (has[i]->getCode() == clothing->getCode()) {
            has.erase(it+i);
        }
    }
    price = calculatePrice();
}

vector<Clothing *> Set::hasClothes() const {
    return has;
}

double Set::calculatePrice() const {
    double sum = 0;
    for (auto * i : has) {
        sum += i->calculatePrice();
    }
    return sum;
}

Garment *Set::SearchGarment(string string1) {
    for(auto i : has) {
        if(i->getCode() == code) return dynamic_cast<Garment*> (i);
    }
    return nullptr;
}
