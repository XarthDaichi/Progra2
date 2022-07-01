//
// Created by Dell on 20/6/2022.
//

#include "Sport.h"

Sport::Sport() : Garment() {}

Sport::Sport(string code, string color, string size, string type, bool characteristic)
        : Garment(code, color, size, type, characteristic) {}

string Sport::showCharacteristic() {
    string out;
    if(type == "Shirt:T-shirt") out = "V-neck: ";
    if(type == "Pant:Shorts") out = "Stamped: ";
    if(type == "Shoe:Tennis") out = "Adidas: ";
    (characteristic) ? out += "Yes" : out += "No";
    return out;
}

Sport::~Sport() = default;
