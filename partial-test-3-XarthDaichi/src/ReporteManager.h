//
// Created by Maikol Guzman Alan on 6/20/22.
//

#ifndef PARTIAL_TEST_3_COLEGIADO_SOLUCION_REPORTEMANAGER_H
#define PARTIAL_TEST_3_COLEGIADO_SOLUCION_REPORTEMANAGER_H

#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "AnalisisTipo.h"
#include "IAnalisis.h"
#include "AnalisisEnfermedades.h"
#include "AnalisisConcordancia.h"
#include "AnalisisBaseNitrogenada.h"

class ReporteManager {
private:
    ostringstream ossData;
    IAnalisis* typeAnalysis;
public:
    ReporteManager();

    virtual ~ReporteManager();

    void limpiar();

    void cargarDatos(vector<Enfermedad> enfermedades, vector<Paciente> pacientes);

    void procesarReporte(AnalisisTipo analisisTipo);

    string str();
};


#endif //PARTIAL_TEST_3_COLEGIADO_SOLUCION_REPORTEMANAGER_H
