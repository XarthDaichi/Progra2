//
// Created by ESCINF on 10/04/2022.
//
#include "Guerrero.h"

Guerrero::Guerrero() {}

Guerrero::~Guerrero() {

}

const std::string &Guerrero::getColor() const {
    return color;
}

void Guerrero::setColor(const std::string &color) {
    Guerrero::color = color;
}

std::string Guerrero::seDefiende() {
    return "Como guerrero me defiendo como gato panza arriba.";
}

std::string Guerrero::ataca() {
    return "Como guerrero me encanta atacar.";
}

std::string Guerrero::muere() {
    return "Ahhhhhh, muero, hoy es buen día para morir.";
}

std::ostream &operator<<(std::ostream &os, const Guerrero &guerrero) {
    os << "[Guerrero] color: " << guerrero.color;
    return os;
}

Guerrero::Guerrero(const std::string &color) : color(color) {}
