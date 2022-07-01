//
// Created by ESCINF on 10/04/2022.
//
#include "RoboCop.h"

RoboCop::RoboCop() {}

RoboCop::~RoboCop() {

}

int RoboCop::getNivelDeDano() const {
    return nivelDeDano;
}

void RoboCop::setNivelDeDano(int nivelDeDano) {
    RoboCop::nivelDeDano = nivelDeDano;
}

int RoboCop::getCodigoDeArmadura() const {
    return codigoDeArmadura;
}

void RoboCop::setCodigoDeArmadura(int codigoDeArmadura) {
    RoboCop::codigoDeArmadura = codigoDeArmadura;
}

std::string RoboCop::dispara() {
    return "Como Robocop, me encanta disparar a los malos";
}

std::string RoboCop::detiene() {
    return "Como Robocop, me encanta detener a los malos";
}

std::string RoboCop::tipoDeMetal() const {
    return Armadura::tipoDeMetal(RoboCop::codigoDeArmadura);
}

int RoboCop::nivelDeResistencia() const {
    return Armadura::nivelDeResistenciaMax(RoboCop::codigoDeArmadura);
}

double RoboCop::valorEnDolares() const {
    return Armadura::valorEnDolares(RoboCop::codigoDeArmadura);
}

std::ostream &operator<<(std::ostream &os, const RoboCop &cop) {
    os << static_cast<const Policia &>(cop) << ' ' << static_cast<const Robot &>(cop) << ", armadura: [Tipo de metal: " << cop.tipoDeMetal() << ", Nivel de resistencia: " << cop.nivelDeResistencia() << ", Valor en dólares: " << cop.valorEnDolares() << "] ," << " numSerie: " << cop.numSerie
       << ", nivelDeDano: " << cop.nivelDeDano << ", codigoDeArmadura: " << cop.codigoDeArmadura;
    return os;
}

const std::string &RoboCop::getNumSerie() const {
    return numSerie;
}

void RoboCop::setNumSerie(const std::string &numSerie) {
    RoboCop::numSerie = numSerie;
}

RoboCop::RoboCop(const std::string &nombre, double nivelDeBateria, int numSensores, const std::string &numSerie,
                 int nivelDeDano, int codigoDeArmadura) : Policia(nombre), Robot(nivelDeBateria, numSensores),
                                                          numSerie(numSerie), nivelDeDano(nivelDeDano),
                                                          codigoDeArmadura(codigoDeArmadura) {}


