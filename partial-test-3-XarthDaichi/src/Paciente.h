//
// Created by Maikol Guzman Alan on 6/20/22.
//

#ifndef PARTIAL_TEST_3_COLEGIADO_SOLUCION_PACIENTE_H
#define PARTIAL_TEST_3_COLEGIADO_SOLUCION_PACIENTE_H

#include <ostream>
#include "Persona.h"

class Paciente : public Persona {
private:
    string secuencia;
public:
    Paciente();

    Paciente(const string &id, const string &nombre, const string &telefono, const string &correo,
             const string &secuencia);

    virtual ~Paciente();

    const string &getSecuencia() const;

    void setSecuencia(const string &secuencia);

    friend ostream &operator<<(ostream &os, const Paciente &paciente);
};


#endif //PARTIAL_TEST_3_COLEGIADO_SOLUCION_PACIENTE_H
