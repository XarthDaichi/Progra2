//
// Created by ESCINF on 10/04/2022.
//
#include "Predator.h"

Predator::Predator() {}

Predator::~Predator() {

}

double Predator::getPeso() const {
    return peso;
}

void Predator::setPeso(double peso) {
    Predator::peso = peso;
}

int Predator::setValor(double x) {
    return x;
}

std::string Predator::toString() {
    return "[--------------------------------------Soy Predator---------------------------]";
}

Predator::Predator(const std::string &nombre, double nivelDeBateria, int numSensores, const std::string &numSerie,
                   int nivelDeDano, int codigoDeArmadura, const std::string &color, double velocidad, double peso)
        : Humanoide(nombre, nivelDeBateria, numSensores, numSerie, nivelDeDano, codigoDeArmadura, color, velocidad),
          peso(peso) {}
