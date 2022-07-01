//
// Created by Maikol Guzman Alan on 6/20/22.
//

#ifndef PARTIAL_TEST_3_COLEGIADO_SOLUCION_PERSONA_H
#define PARTIAL_TEST_3_COLEGIADO_SOLUCION_PERSONA_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Persona {
private:
    string ID;
    string nombre;
    string telefono;
    string correo;
public:
    Persona();

    Persona(const string &id, const string &nombre, const string &telefono, const string &correo);

    virtual ~Persona();

    const string &getId() const;

    void setId(const string &id);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getTelefono() const;

    void setTelefono(const string &telefono);

    const string &getCorreo() const;

    void setCorreo(const string &correo);

    friend ostream &operator<<(ostream &os, const Persona &persona);
};


#endif //PARTIAL_TEST_3_COLEGIADO_SOLUCION_PERSONA_H
