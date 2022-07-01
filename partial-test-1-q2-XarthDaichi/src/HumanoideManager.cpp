//
// Created by ESCINF on 10/04/2022.
//
#include "HumanoideManager.h"

HumanoideManager::~HumanoideManager() {

}

void HumanoideManager::ingresaHumanoide(Humanoide* humanoide) {
    humanoideLista.push_back(humanoide);
}

std::vector<Humanoide *> HumanoideManager::getHumanoideLista() const {
    return humanoideLista;
}

void HumanoideManager::setHumanoideLista(std::vector<Humanoide *> &humanoideLista) {
    HumanoideManager::humanoideLista = humanoideLista;
}

std::string HumanoideManager::retornaSoloAliens() {
    std::stringstream s;
    for (Humanoide* i : humanoideLista) {
        Alien* temp = dynamic_cast<Alien*> (i);
        if (temp->getEstatura()) {
            s << temp;
        }
    }
    return s.str();
}

std::string HumanoideManager::retornaTodos() {
    std::stringstream s;
    for (Humanoide* i : humanoideLista) {
        s << i;
    }
    return s.str();
}

HumanoideManager::HumanoideManager(std::vector<Humanoide *> &humanoideLista) : humanoideLista(humanoideLista) {}
