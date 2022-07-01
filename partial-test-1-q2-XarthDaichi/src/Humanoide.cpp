//
// Created by ESCINF on 10/04/2022.
//
#include "Humanoide.h"

Humanoide::Humanoide() {}

Humanoide::~Humanoide() {

}

double Humanoide::getVelocidad() const {
    return velocidad;
}

void Humanoide::setVelocidad(double velocidad) {
    Humanoide::velocidad = velocidad;
}

std::string Humanoide::corre() const {
    std::stringstream s;
    s << "Como humanoide, me gusta correr a una velocidad de " << std::fixed << std::setprecision(6) << Humanoide::getVelocidad() << " km/s.";
    return s.str();
}

std::ostream &operator<<(std::ostream &os, const Humanoide &humanoide) {
    os << static_cast<const RoboCop &>(humanoide) << ' ' << static_cast<const Guerrero &>(humanoide) << " velocidad: "
       << humanoide.velocidad;
    return os;
}

Humanoide::Humanoide(const std::string &nombre, double nivelDeBateria, int numSensores, const std::string &numSerie,
                     int nivelDeDano, int codigoDeArmadura, const std::string &color, double velocidad) : RoboCop(
        nombre, nivelDeBateria, numSensores, numSerie, nivelDeDano, codigoDeArmadura), Guerrero(color), velocidad(
        velocidad) {}
