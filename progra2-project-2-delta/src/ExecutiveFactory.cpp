//
// Created by Dell on 21/6/2022.
//

#include "ExecutiveFactory.h"

ExecutiveFactory::ExecutiveFactory() = default;

ExecutiveFactory::~ExecutiveFactory() = default;

IGarment *ExecutiveFactory::createShirt(string code, string color, string size, bool characteristic) {
    return new Executive(code, color, size, "Shirt:LongSleeve", characteristic);
}

IGarment *ExecutiveFactory::createPant(string code, string color, string size, bool characteristic) {
    return new Executive(code, color, size, "Pant:DressUp", characteristic);
}

IGarment *ExecutiveFactory::createShoe(string code, string color, string size, bool characteristic) {
    return new Executive(code, color, size, "Shoe:Executive", characteristic);
}

ISuit *ExecutiveFactory::createSuit(string code, vector<Clothing*> has) {
    return new Suit(code,"Executive",has);
}

ISet *ExecutiveFactory::createSet(string code, vector<Clothing*> has) {
    return new Set(code, has);
}
