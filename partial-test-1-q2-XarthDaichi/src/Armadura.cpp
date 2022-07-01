//
// Created by ESCINF on 10/04/2022.
//
#include "Armadura.h"

Armadura::Armadura() {}

Armadura::~Armadura() {

}

std::string Armadura::tipoDeMetal(int codDeArmadura) {
    switch(codDeArmadura) {
        case 1:
            return "Aluminio";
        case 2:
            return "Titanio";
        case 3:
            return "Acero";
        case 4:
            return "Oro";
        default:
            return "Error: Codigo invalido";
    }
}

int Armadura::nivelDeResistenciaMax(int codDeArmadura) {
    switch(codDeArmadura) {
        case 1:
            return 50;
        case 2:
            return 95;
        case 3:
            return 85;
        case 4:
            return 70;
        default:
            return -1;
    }
}

double Armadura::valorEnDolares(int codDeArmadura) {
    switch(codDeArmadura) {
        case 1:
            return 2.5;
        case 2:
            return 3.4;
        case 3:
            return 2.9;
        case 4:
            return 1.7;
        default:
            return -1;
    }
}
