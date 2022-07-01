//
// Created by Maikol Guzman Alan on 6/20/22.
//

#include "Enfermedad.h"

Enfermedad::Enfermedad() {}

Enfermedad::Enfermedad(const string &enfermedad, const string &secuencia) : enfermedad(enfermedad),
                                                                            secuencia(secuencia) {}

Enfermedad::~Enfermedad() {

}

const string &Enfermedad::getEnfermedad() const {
    return enfermedad;
}

void Enfermedad::setEnfermedad(const string &enfermedad) {
    Enfermedad::enfermedad = enfermedad;
}

const string &Enfermedad::getSecuencia() const {
    return secuencia;
}

void Enfermedad::setSecuencia(const string &secuencia) {
    Enfermedad::secuencia = secuencia;
}

ostream &operator<<(ostream &os, const Enfermedad &enfermedad) {
    os << "enfermedad: " << enfermedad.enfermedad << " secuencia: " << enfermedad.secuencia;
    return os;
}
