//
// Created by Maikol Guzman Alan on 6/20/22.
//

#ifndef PARTIAL_TEST_3_COLEGIADO_SOLUCION_ANALISISENFERMEDADES_H
#define PARTIAL_TEST_3_COLEGIADO_SOLUCION_ANALISISENFERMEDADES_H

#include "IAnalisis.h"

class AnalisisEnfermedades : public IAnalisis {
public:
    AnalisisEnfermedades();

    virtual ~AnalisisEnfermedades();

    void mostrarAnalisis(ostringstream &oss, vector<Enfermedad> enfermedades, vector<Paciente> pacientes) override;

    int calcularRepeticiones(const string& textoBuscar, const string& textoBase);
};


#endif //PARTIAL_TEST_3_COLEGIADO_SOLUCION_ANALISISENFERMEDADES_H
