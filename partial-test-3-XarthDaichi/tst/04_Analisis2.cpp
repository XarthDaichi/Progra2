//
// Created by Maikol Guzman Alan on 6/21/22.
//

#include "../src/ArchivoManager.h"
#include "../src/ReporteManager.h"
#include "../lib/catch2/catch.hpp"

// Descomentar el bloque siguiente para autoevaluación, la ejecución correcta de esta prueba le genera los puntos
// Hacer commit de la prueba sin el bloque comentado

TEST_CASE("Análisis #2 Base Nitrogenada", "[AnalisisBaseNitrogenada]") {
    string archivoEnfermedades = "files/enfermedades.txt";
    string archivoPacientes = "files/pacientes.txt";
    ArchivoManager archivoManager;
    vector<Enfermedad> enfermedades = archivoManager.cargarEnfermedades(archivoEnfermedades);
    vector<Paciente> pacientes = archivoManager.cargarPacientes(archivoPacientes);

    ReporteManager reporteManager;
    reporteManager.limpiar();
    reporteManager.procesarReporte(AnalisisTipo::ANALISIS_BASE_NITROGENADA);
    reporteManager.cargarDatos(enfermedades, pacientes);

    //Remove new line from multiline string
    string str = reporteManager.str();
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

    REQUIRE(str == "Felix Reese[A-29.993965%,T-15.027158%,G-29.993965%,C-24.984913];Hu Frank[A-30.000000%,T-15.000000%,G-30.000000%,C-25.000000];Hu Hinton[A-29.993855%,T-15.058390%,G-29.993855%,C-24.953903];Kevin Marquez[A-29.981606%,T-15.082771%,G-29.981606%,C-24.954016];Jasper Saunders[A-29.980406%,T-15.088178%,G-29.980406%,C-24.951012];Cullen Porter[A-29.976852%,T-15.046296%,G-29.976852%,C-25.000000];Ray Wilkinson[A-29.974161%,T-15.051680%,G-29.974161%,C-25.000000];Ethan James[A-29.952551%,T-15.124556%,G-29.952551%,C-24.970345];Wallace Ray[A-29.967070%,T-15.093304%,G-29.967070%,C-24.972557];Branden Fox[A-29.974325%,T-15.275995%,G-29.910141%,C-24.839539];");
}
