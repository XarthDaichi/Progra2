//
// Created by Maikol Guzman Alan on 6/20/22.
//

#ifndef PARTIAL_TEST_3_COLEGIADO_SOLUCION_ARCHIVOMANAGER_H
#define PARTIAL_TEST_3_COLEGIADO_SOLUCION_ARCHIVOMANAGER_H

#include "IOperaciones.h"

class ArchivoManager : public IOperaciones {
public:
    ArchivoManager();

    virtual ~ArchivoManager();

    vector<Enfermedad> cargarEnfermedades(string fileName) override;

    vector<Paciente> cargarPacientes(string fileName) override;
};


#endif //PARTIAL_TEST_3_COLEGIADO_SOLUCION_ARCHIVOMANAGER_H
