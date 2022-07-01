//
// Created by Dell on 20/6/2022.
//

#include "Executive.h"

Executive::Executive() : Garment() {}

Executive::Executive(string code, string color, string size, string type, bool characteristic)
    : Garment(code, color, size, type, characteristic) {}

string Executive::showCharacteristic() {
    string out;
    if(type == "Shirt:LongSleeve") out = "Plain: ";
    if(type == "Pant:DressUp") out = "Casimir: ";
    if(type == "Shoe:Executive") out = "Fine: ";
    (characteristic) ? out += "Yes" : out += "No";
    return out;
}

Executive::~Executive() = default;
