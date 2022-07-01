//
// Created by Maikol Guzman Alan on 6/21/22.
//

#include "../src/ArchivoManager.h"
#include "../lib/catch2/catch.hpp"

// Descomentar el bloque siguiente para autoevaluación, la ejecución correcta de esta prueba le genera los puntos
// Hacer commit de la prueba sin el bloque comentado

TEST_CASE("Procesamiento correcto de las enfermedades", "[CargaEnfermedades]") {
    ArchivoManager archivoManager;
    string archivoEnfermedades = "files/enfermedades.txt";
    vector<Enfermedad> enfermedades = archivoManager.cargarEnfermedades(archivoEnfermedades);

    REQUIRE(enfermedades.size() == 9);
    REQUIRE(enfermedades[0].getEnfermedad() == "Down syndrome");
    REQUIRE(enfermedades[0].getSecuencia() == "CGTTTA");
    REQUIRE(enfermedades[8].getEnfermedad() == "Trisomy 13");
    REQUIRE(enfermedades[8].getSecuencia() == "GTACATCG");
}

TEST_CASE("Excepción en carga de enfermedades", "[CargaEnfermedadesError]") {
    ArchivoManager archivoManager;
    string archivoEnfermedades = "noexiste.txt";

    REQUIRE_THROWS_AS(archivoManager.cargarEnfermedades(archivoEnfermedades), std::exception);
    REQUIRE_THROWS_MATCHES(archivoManager.cargarEnfermedades(archivoEnfermedades), std::exception,
                           Catch::Message("Could not open the file [noexiste.txt]"));
}
