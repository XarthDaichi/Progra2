//
// Created by Maikol Guzman Alan on 4/8/22.
//

#include "../src/Grupo.h"
#include "../src/Persona.h"
#include "../src/Zona.h"
#include "../lib/catch2/catch.hpp"

// Descomentar el bloque siguiente para autoevaluación, la ejecución correcta de esta prueba le genera los puntos
// Valor total de este Ejercicio: 10 pts
// Hacer commit de la prueba sin el bloque comentado

TEST_CASE("Crear Zona Sarapiqui y agregar los contratistas", "[Zona_1]"){
    Grupo grupoTrabajadores (55, "GTRAB", "Trabajadores");
    Grupo grupoMediosComunicacion (37, "GMEDI", "Medios de Comunicacion");

    Zona zonaSarapiqui (new Persona ("Maria Salguero", "1-2343-2222", 45), "Zona Sarapiqui");
    zonaSarapiqui.agregar(&grupoMediosComunicacion);
    zonaSarapiqui.agregar(&grupoTrabajadores);

    REQUIRE( zonaSarapiqui.getZonaLista().size() == 2);
}

TEST_CASE("toString() de Zona Golfito", "[Zona_2]"){
    Grupo grupoContratistas (43, "GCONT", "Contratistas");
    Zona zonaGolfito (new Persona ("Juan Perez", "1-1234-0342", 35), "Zona Golfito");
    zonaGolfito.agregar(&grupoContratistas);

    REQUIRE( zonaGolfito.toString() == "presupuesto: 60000000 cantidadDeActividades: 42 cantidadDeAsociados: 44 coordinador: nombre: Juan Perez cedula: 1-1234-0342 edad: 35 nombreZona: Zona Golfito");
}
