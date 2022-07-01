//
// Created by Maikol Guzman Alan on 6/20/22.
//

#include "Paciente.h"


Paciente::Paciente() {}

Paciente::Paciente(const string &id, const string &nombre, const string &telefono, const string &correo,
                   const string &secuencia) : Persona(id, nombre, telefono, correo), secuencia(secuencia) {}

Paciente::~Paciente() {

}

const string &Paciente::getSecuencia() const {
    return secuencia;
}

void Paciente::setSecuencia(const string &secuencia) {
    Paciente::secuencia = secuencia;
}

ostream &operator<<(ostream &os, const Paciente &paciente) {
    os << static_cast<const Persona &>(paciente) << " secuencia: " << paciente.secuencia;
    return os;
}
