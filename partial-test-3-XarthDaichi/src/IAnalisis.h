//
// Created by Maikol Guzman Alan on 6/20/22.
//

#ifndef PARTIAL_TEST_3_COLEGIADO_SOLUCION_IANALISIS_H
#define PARTIAL_TEST_3_COLEGIADO_SOLUCION_IANALISIS_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Enfermedad.h"
#include "Paciente.h"
using namespace std;

class IAnalisis {


public:
    virtual ~IAnalisis() {

    }
    virtual void mostrarAnalisis(ostringstream &oss, vector<Enfermedad> enfermedades, vector<Paciente> pacientes) = 0;
};

#endif //PARTIAL_TEST_3_COLEGIADO_SOLUCION_IANALISIS_H
