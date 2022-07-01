//
// Created by ESCINF on 10/04/2022.
//
#include "Policia.h"

Policia::Policia() {}

Policia::~Policia() {

}

const std::string &Policia::getNombre() const {
    return nombre;
}

void Policia::setNombre(const std::string &nombre) {
    Policia::nombre = nombre;
}

std::string Policia:: aprende() {return "Aprendo como un policia.";}
std::string Policia:: aplicaJusticia() {return "Aplico la justicia como un policia.";}
std::string Policia:: ayuda() {return "Ayudo a la gente como a un policia.";}

std::ostream &operator<<(std::ostream &os, const Policia &policia) {
    os << "[Policia] nombre: " << policia.nombre;
    return os;
}

Policia::Policia(const std::string &nombre) : nombre(nombre) {}
