//
// Created by Xarthy on 0016 June 16, 2022.
//

#include "Suit.h"

Suit::Suit() = default;

Suit::Suit(const string &code, const string &type, const vector<Clothing *> &has) : Clothing(code), type(type), has(has) {
    price = Suit::calculatePrice();
}

Suit::~Suit() = default;

void Suit::setHas(const vector<Clothing *> &has) {
    Suit::has = has;
    price = calculatePrice();
}

const string &Suit::getType() const {
    return type;
}

void Suit::setType(const string &type) {
    Suit::type = type;
}

ostream &operator<<(ostream &os, const Suit &suit) {
    os << static_cast<const Clothing &>(suit) << " has: ";
    for (auto * i : suit.has) {
        Garment* iGar = dynamic_cast<Garment*> (&*i);
        if(iGar) os << *iGar << " - ";
    }
    return os;
}

string Suit::toString() const {
    stringstream s;
    s << (*this);
    return s.str();
}

void Suit::add(Clothing *clothing) {
    has.push_back(clothing);
    price = calculatePrice();
}

void Suit::remove(Clothing *clothing) {
    if(has.empty()) throw std::out_of_range("Suit::remove: empty vector (has)");
    auto it = has.begin();
    for(int i = 0; i < has.size(); i++) {
        if (has[i]->getCode() == clothing->getCode()) {
            has.erase(it+i);
        }
    }
    price = calculatePrice();
}

vector<Clothing *> Suit::hasClothes() const {
    return has;
}

double Suit::calculatePrice() const {
    double sum = 0;
    for (auto * i : has) {
        sum += i->calculatePrice();
    }
    return sum;
}

Garment *Suit::SearchGarment(string code) {
    for(auto i : has) {
        if(i->getCode() == code) return dynamic_cast<Garment*> (i);
    }
    return nullptr;
}
