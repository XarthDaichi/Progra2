//
// Created by Maikol Guzman Alan on 6/21/22.
//

#include "../src/ArchivoManager.h"
#include "../src/ReporteManager.h"
#include "../lib/catch2/catch.hpp"

// Descomentar el bloque siguiente para autoevaluación, la ejecución correcta de esta prueba le genera los puntos
// Hacer commit de la prueba sin el bloque comentado

TEST_CASE("Análisis #3 Concordancia", "[AnalisisConcordancia]") {
    string archivoEnfermedades = "files/enfermedades.txt";
    string archivoPacientes = "files/pacientes.txt";
    ArchivoManager archivoManager;
    vector<Enfermedad> enfermedades = archivoManager.cargarEnfermedades(archivoEnfermedades);
    vector<Paciente> pacientes = archivoManager.cargarPacientes(archivoPacientes);

    ReporteManager reporteManager;
    reporteManager.limpiar();
    reporteManager.procesarReporte(AnalisisTipo::ANALISIS_CONCORDANCIA);
    reporteManager.cargarDatos(enfermedades, pacientes);

    //Remove new line from multiline string
    string str = reporteManager.str();
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

    REQUIRE(str == "22542305499-Hu Frank-blandit@nuncsitamet.edu [Turner-MEDIA];35726308599-Hu Hinton-turpis.non.enim@ullamcorperDuisat.net [Turner-MEDIA];50635124899-Kevin Marquez-malesuada@Praesentluctus.com [Turner-ALTA];36754600599-Ethan James-a.ultricies@acipsum.org [Turner-ALTA];87759707299-Branden Fox-sit@turpisnecmauris.ca [Diabetes-MEDIA];");
}
