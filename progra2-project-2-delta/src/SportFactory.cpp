//
// Created by Dell on 21/6/2022.
//

#include "SportFactory.h"

SportFactory::SportFactory() = default;

SportFactory::~SportFactory() = default;

IGarment *SportFactory::createShirt(string code, string color, string size, bool characteristic) {
    return new Sport(code, color, size, "Shirt:T-shirt", characteristic);
}

IGarment *SportFactory::createPant(string code, string color, string size, bool characteristic) {
    return new Sport(code, color, size, "Pant:Shorts", characteristic);
}

IGarment *SportFactory::createShoe(string code, string color, string size, bool characteristic) {
    return new Sport(code, color, size, "Shoe:Tennis", characteristic);
}

ISuit *SportFactory::createSuit(string code, vector<Clothing*> has) {
    return new Suit(code, "Sport", has);
}

ISet *SportFactory::createSet(string code, vector<Clothing*> has) {
    return new Set(code, has);
}
