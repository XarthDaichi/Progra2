//
// Created by Maikol Guzman Alan on 6/20/22.
//

#include "Persona.h"

Persona::Persona() {}

Persona::Persona(const string &id, const string &nombre, const string &telefono, const string &correo) : ID(id),
                                                                                                         nombre(nombre),
                                                                                                         telefono(
                                                                                                                 telefono),
                                                                                                         correo(correo) {}

Persona::~Persona() {

}

const string &Persona::getId() const {
    return ID;
}

void Persona::setId(const string &id) {
    ID = id;
}

const string &Persona::getNombre() const {
    return nombre;
}

void Persona::setNombre(const string &nombre) {
    Persona::nombre = nombre;
}

const string &Persona::getTelefono() const {
    return telefono;
}

void Persona::setTelefono(const string &telefono) {
    Persona::telefono = telefono;
}

const string &Persona::getCorreo() const {
    return correo;
}

void Persona::setCorreo(const string &correo) {
    Persona::correo = correo;
}

ostream &operator<<(ostream &os, const Persona &persona) {
    os << "ID: " << persona.ID << " nombre: " << persona.nombre << " telefono: " << persona.telefono << " correo: "
       << persona.correo;
    return os;
}
