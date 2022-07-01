//
// Created by ESCINF on 10/04/2022.
//
#include "Robot.h"

Robot::Robot() {}

Robot::~Robot() {}

double Robot::getNivelDeBateria() const {
    return nivelDeBateria;
}

void Robot::setNivelDeBateria(double nivelDeBateria) {
    Robot::nivelDeBateria = nivelDeBateria;
}

int Robot::getNumSensores() const {
    return numSensores;
}

void Robot::setNumSensores(int numSensores) {
    Robot::numSensores = numSensores;
}

std::string Robot::seConfigura() {
    return "Yo, como robot me puedo configurar.";
}

std::string Robot::seRecarga() {
    return "Yo, como robot busco como recargar la bateria";
}

std::ostream &operator<<(std::ostream &os, const Robot &robot) {
    os << "[Robot] nivelDeBateria: " << robot.nivelDeBateria << ", numSensores: " << robot.numSensores;
    return os;
}

Robot::Robot(double nivelDeBateria, int numSensores) : nivelDeBateria(nivelDeBateria), numSensores(numSensores) {}


