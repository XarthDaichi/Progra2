#include "Persona.h"

Persona::Persona() {}

Persona::Persona(const string &nombre, const string &cedula, int edad) : nombre(nombre), cedula(cedula), edad(edad) {}

const string &Persona::getNombre() const {
    return nombre;
}

void Persona::setNombre(const string &nombre) {
    Persona::nombre = nombre;
}

const string &Persona::getCedula() const {
    return cedula;
}

void Persona::setCedula(const string &cedula) {
    Persona::cedula = cedula;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::setEdad(int edad) {
    Persona::edad = edad;
}

ostream &operator<<(ostream &os, const Persona &persona) {
    os << "nombre: " << persona.nombre << " cedula: " << persona.cedula << " edad: " << persona.edad;
    return os;
}

string Persona::toString() const {
    stringstream s;
    s << (*this);
    return s.str();
}
