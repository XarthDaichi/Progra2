//
// Created by Dell on 21/6/2022.
//

#include "WorkFactory.h"

WorkFactory::WorkFactory() = default;

WorkFactory::~WorkFactory() = default;

IGarment *WorkFactory::createShirt(string code, string color, string size, bool characteristic) {
    return new Work(code, color, size, "Shirt:WithSquares", characteristic);
}

IGarment *WorkFactory::createPant(string code, string color, string size, bool characteristic) {
    return new Work(code, color, size, "Pant:Jeans", characteristic);
}

IGarment *WorkFactory::createShoe(string code, string color, string size, bool characteristic) {
    return new Work(code, color, size, "Shoe:Boots", characteristic);
}

ISuit *WorkFactory::createSuit(string code, vector<Clothing *> has) {
    return new Suit(code, "Work", has);
}

ISet *WorkFactory::createSet(string code, vector<Clothing *> has) {
    return new Set(code, has);
}
