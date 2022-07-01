//
// Created by Maikol Guzman Alan on 6/20/22.
//

#include "ReporteManager.h"

ReporteManager::ReporteManager() = default;

ReporteManager::~ReporteManager() = default;

void ReporteManager::limpiar() {
    ossData.str("");
    ossData.clear();
}

void ReporteManager::cargarDatos(vector<Enfermedad> enfermedades, vector<Paciente> pacientes) {
    typeAnalysis->mostrarAnalisis(ossData, enfermedades, pacientes);
}

void ReporteManager::procesarReporte(AnalisisTipo analisisTipo) {
    switch (analisisTipo) {
        case AnalisisTipo::ANALISIS_ENFERMEDADES:
            typeAnalysis = new AnalisisEnfermedades();
            break;
        case AnalisisTipo::ANALISIS_BASE_NITROGENADA:
            typeAnalysis = new AnalisisBaseNitrogenada();
            break;
        case AnalisisTipo::ANALISIS_CONCORDANCIA:
            typeAnalysis = new AnalisisConcordancia();
    }
}

string ReporteManager::str() {
    return ossData.str();
}
