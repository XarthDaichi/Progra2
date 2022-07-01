//
// Created by Maikol Guzman Alan on 6/20/22.
//

#ifndef PARTIAL_TEST_3_COLEGIADO_SOLUCION_ENFERMEDAD_H
#define PARTIAL_TEST_3_COLEGIADO_SOLUCION_ENFERMEDAD_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Enfermedad {
private:
    string enfermedad;
    string secuencia;
public:
    Enfermedad();

    Enfermedad(const string &enfermedad, const string &secuencia);

    virtual ~Enfermedad();

    const string &getEnfermedad() const;

    void setEnfermedad(const string &enfermedad);

    const string &getSecuencia() const;

    void setSecuencia(const string &secuencia);

    friend ostream &operator<<(ostream &os, const Enfermedad &enfermedad);
};


#endif //PARTIAL_TEST_3_COLEGIADO_SOLUCION_ENFERMEDAD_H
