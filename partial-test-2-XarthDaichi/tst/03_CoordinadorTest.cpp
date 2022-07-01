//
// Created by Maikol Guzman Alan on 4/8/22.
//

#include "../src/Servicio.h"
#include "../src/Persona.h"
#include "../lib/catch2/catch.hpp"

// Descomentar el bloque siguiente para autoevaluación, la ejecución correcta de esta prueba le genera los puntos
// Valor total de este Ejercicio: 2 pts
// Hacer commit de la prueba sin el bloque comentado

TEST_CASE("toString() de Coordinador", "[Coordinador]"){
    Persona coordinador;
    coordinador.setNombre("David Munoz");
    coordinador.setCedula("6-2345-1111");
    coordinador.setEdad(29);
    
    REQUIRE( coordinador.toString() == "nombre: David Munoz cedula: 6-2345-1111 edad: 29");
}
