//
// Created by Maikol Guzman on 3/18/22.
//
#include <ostream>
#include <iostream>
#include <vector>
#include "Enfermedad.h"
#include "Paciente.h"
#include "ArchivoManager.h"
#include "ReporteManager.h"

using namespace std;

int main() {
    cout << "Welcome to the UNA! (VIRTUAL)" << endl;
    cout << "Examen Parcial #3" << endl << endl;

    /**
    try {
        string archivoEnfermedades = "files/enfermedades.txt";
        string archivoPacientes = "files/pacientes.txt";
        ArchivoManager archivoManager;
        vector<Enfermedad> enfermedades = archivoManager.cargarEnfermedades(archivoEnfermedades);
        vector<Paciente> pacientes = archivoManager.cargarPacientes(archivoPacientes);

        ReporteManager reporteManager;

        cout << "Reporte 1" << endl;
        reporteManager.limpiar();
        reporteManager.procesarReporte(AnalisisTipo::ANALISIS_ENFERMEDADES);
        reporteManager.cargarDatos(enfermedades, pacientes);
        cout << reporteManager.str() << endl;

        cout << "Reporte 2" << endl;
        reporteManager.limpiar();
        reporteManager.procesarReporte(AnalisisTipo::ANALISIS_BASE_NITROGENADA);
        reporteManager.cargarDatos(enfermedades, pacientes);
        cout << reporteManager.str() << endl;

        cout << "Reporte 3" << endl;
        reporteManager.limpiar();
        reporteManager.procesarReporte(AnalisisTipo::ANALISIS_CONCORDANCIA);
        reporteManager.cargarDatos(enfermedades, pacientes);
        cout << reporteManager.str() << endl;
    } catch (exception& ex) {
        cerr << ex.what() << '\n' << std::endl;
    }
    **/
    return EXIT_SUCCESS;
}
