//
// Created by Dell on 20/6/2022.
//

#include "Work.h"

Work::Work() : Garment() {}

Work::Work(string code, string color, string size, string type, bool characteristic)
        : Garment(code, color, size, type, characteristic) {}

string Work::showCharacteristic() {
    string out;
    if(type == "Shirt:WithSquares") out = "Big squares: ";
    if(type == "Pant:Jeans") out = "Tight: ";
    if(type == "Shoe:Boots") out = "High: ";
    (characteristic) ? out += "Yes" : out += "No";
    return out;
}

Work::~Work() = default;