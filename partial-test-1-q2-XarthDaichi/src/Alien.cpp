//
// Created by ESCINF on 10/04/2022.
//
#include "Alien.h"

Alien::Alien() {}

Alien::~Alien() {

}

double Alien::getEstatura() const {
    return estatura;
}

void Alien::setEstatura(double estatura) {
    Alien::estatura = estatura;
}

int Alien::setValor(double x) {
    return x;
}

std::ostream &operator<<(std::ostream &os, const Alien &alien) {
    os << static_cast<const Humanoide &>(alien) << " estatura: " << alien.estatura;
    return os;
}

Alien::Alien(const std::string &nombre, double nivelDeBateria, int numSensores, const std::string &numSerie,
             int nivelDeDano, int codigoDeArmadura, const std::string &color, double velocidad, double estatura)
        : Humanoide(nombre, nivelDeBateria, numSensores, numSerie, nivelDeDano, codigoDeArmadura, color, velocidad),
          estatura(estatura) {}


std::string Alien::toString() {
    std::stringstream s;
    s << (*this);
    return s.str();
}


