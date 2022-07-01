//
// Created by Maikol Guzman Alan on 4/8/22.
//

#include "../src/Servicio.h"
#include "../lib/catch2/catch.hpp"

// Descomentar el bloque siguiente para autoevaluación, la ejecución correcta de esta prueba le genera los puntos
// Valor total de este Ejercicio: 13 pts
// Hacer commit de la prueba sin el bloque comentado


TEST_CASE("Actividades por año", "[Servicio_1]"){
    Servicio servicio;

    REQUIRE( servicio.obtenerActividadPorAno(15) == 30);
    REQUIRE( servicio.obtenerActividadPorAno(52) == 35);
    REQUIRE( servicio.obtenerActividadPorAno(55) == 16);
    REQUIRE( servicio.obtenerActividadPorAno(39) == 11);
    REQUIRE( servicio.obtenerActividadPorAno(33) == 23);
    REQUIRE( servicio.obtenerActividadPorAno(43) == 42);
    REQUIRE( servicio.obtenerActividadPorAno(37) == 18);
}

TEST_CASE("Presupuesto anual", "[Servicio_2]"){
    Servicio servicio;

    REQUIRE( servicio.obtenerPresupuesto(15) == 33000000);
    REQUIRE( servicio.obtenerPresupuesto(52) == 39000000);
    REQUIRE( servicio.obtenerPresupuesto(55) == 15000000);
    REQUIRE( servicio.obtenerPresupuesto(39) == 14000000);
    REQUIRE( servicio.obtenerPresupuesto(33) == 25000000);
    REQUIRE( servicio.obtenerPresupuesto(43) == 60000000);
    REQUIRE( servicio.obtenerPresupuesto(37) == 15000000);
}

TEST_CASE("Cantidad de asociados", "[Servicio_3]"){
    Servicio servicio;

    REQUIRE( servicio.obtenerCantidadAsociados(15) == 35);
    REQUIRE( servicio.obtenerCantidadAsociados(52) == 22);
    REQUIRE( servicio.obtenerCantidadAsociados(55) == 11);
    REQUIRE( servicio.obtenerCantidadAsociados(39) == 12);
    REQUIRE( servicio.obtenerCantidadAsociados(33) == 7);
    REQUIRE( servicio.obtenerCantidadAsociados(43) == 44);
    REQUIRE( servicio.obtenerCantidadAsociados(37) == 23);
}



