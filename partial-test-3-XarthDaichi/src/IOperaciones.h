//
// Created by Maikol Guzman Alan on 6/20/22.
//

#ifndef PARTIAL_TEST_3_COLEGIADO_SOLUCION_IOPERACIONES_H
#define PARTIAL_TEST_3_COLEGIADO_SOLUCION_IOPERACIONES_H

#include <algorithm>
#include <vector>
#include <fstream>
#include "Paciente.h"
#include "Enfermedad.h"

class IOperaciones {
public:
    virtual ~IOperaciones() {}

    virtual vector<Enfermedad> cargarEnfermedades(string fileName) = 0;
    virtual vector<Paciente> cargarPacientes(string fileName) = 0;

};
#endif //PARTIAL_TEST_3_COLEGIADO_SOLUCION_IOPERACIONES_H
