//
// Created by Maikol Guzman Alan on 4/8/22.
//

#include "../src/Grupo.h"
#include "../src/Persona.h"
#include "../src/Zona.h"
#include "../lib/catch2/catch.hpp"

// Descomentar el bloque siguiente para autoevaluación, la ejecución correcta de esta prueba le genera los puntos
// Valor total de este Ejercicio: 70 pts
// Hacer commit de la prueba sin el bloque comentado

TEST_CASE("Presupuesto Zona Santa Cruz", "[Calculo_1]"){
    Grupo grupoSocios (52, "GSOCI", "Socios");

    Zona zonaSantaCruz (new Persona ("David Munoz", "6-2345-1111", 29), "Zona Santa Cruz");
    zonaSantaCruz.agregar(&grupoSocios);

    REQUIRE( zonaSantaCruz.obtenerTotalPresupuesto() == 39000000);
}

TEST_CASE("Presupuesto Zona Brunca", "[Calculo_2]"){
    Grupo grupoClientes (39, "GCLIE", "Clientes");
    Grupo grupoContratistas (43, "GCONT", "Contratistas");

    Zona zonaGolfito (new Persona ("Juan Perez", "1-1234-0342", 35), "Zona Golfito");
    zonaGolfito.agregar(&grupoContratistas);

    Zona zonaPerezZeledon (new Persona ("Cesar Gutierrez", "1-1455-2234", 28), "Zona Perez Zeledon");
    zonaPerezZeledon.agregar(&grupoClientes);
    zonaPerezZeledon.agregar(&zonaGolfito);

    Zona zonaBrunca (new Persona ("Antonio Jesus", "1-1455-3466", 57), "Zona Brunca");
    zonaBrunca.agregar(&zonaPerezZeledon);

    REQUIRE( zonaBrunca.obtenerTotalPresupuesto() == 74000000);
}

TEST_CASE("Actividades por año Zona Huetar-Norte", "[Calculo_3]"){
    Grupo grupoMediosComunicacion (37, "GMEDI", "Medios de Comunicacion");
    Grupo grupoTrabajadores (55, "GTRAB", "Trabajadores");

    Zona zonaSarapiqui (new Persona ("Maria Salguero", "1-2343-2222", 45), "Zona Sarapiqui");
    zonaSarapiqui.agregar(&grupoMediosComunicacion);
    zonaSarapiqui.agregar(&grupoTrabajadores);

    Zona zonaHuetarNorte (new Persona ("Marcela Quiros", "5-2343-2222", 34), "Zona Huetar-Norte");
    zonaHuetarNorte.agregar(&zonaSarapiqui);

    REQUIRE( zonaHuetarNorte.obtenerTotalCantActividades() == 34);
}

TEST_CASE("Asociados para toda la Zona Nacional omitiendo la Chorotega", "[Calculo_4]"){
    Grupo grupoTrabajadores (55, "GTRAB", "Trabajadores");
    Grupo grupoClientes (39, "GCLIE", "Clientes");
    Grupo grupoCompetidores (33, "GCOMP", "Competidores");
    Grupo grupoContratistas (43, "GCONT", "Contratistas");
    Grupo grupoMediosComunicacion (37, "GMEDI", "Medios de Comunicacion");

    Zona zonaSarapiqui (new Persona ("Maria Salguero", "1-2343-2222", 45), "Zona Sarapiqui");
    zonaSarapiqui.agregar(&grupoMediosComunicacion);
    zonaSarapiqui.agregar(&grupoTrabajadores);

    Zona zonaHuetarNorte (new Persona ("Marcela Quiros", "5-2343-2222", 34), "Zona Huetar-Norte");
    zonaHuetarNorte.agregar(&zonaSarapiqui);

    Zona zonaGolfito (new Persona ("Juan Perez", "1-1234-0342", 35), "Zona Golfito");
    zonaGolfito.agregar(&grupoContratistas);

    Zona zonaPerezZeledon (new Persona ("Cesar Gutierrez", "1-1455-2234", 28), "Zona Perez Zeledon");
    zonaPerezZeledon.agregar(&grupoClientes);
    zonaPerezZeledon.agregar(&zonaGolfito);

    Zona zonaBrunca (new Persona ("Antonio Jesus", "1-1455-3466", 57), "Zona Brunca");
    zonaBrunca.agregar(&zonaPerezZeledon);

    Zona zonaNacional (new Persona ("Rodrigo Chavez", "1-1080-0342", 43), "Zona Nacional");
    zonaNacional.agregar(&zonaBrunca);
    zonaNacional.agregar(&grupoCompetidores);
    zonaNacional.agregar(&zonaHuetarNorte);

    REQUIRE( zonaNacional.obtenerTotalCantidadAsociados() == 97);
}

TEST_CASE("Presupuesto Nacional excepto Zona Huetar-Norte", "[Calculo_5]"){
    Grupo grupoAccionistas (15, "GACCI", "Accionistas");
    Grupo grupoSocios (52, "GSOCI", "Socios");
    Grupo grupoClientes (39, "GCLIE", "Clientes");
    Grupo grupoCompetidores (33, "GCOMP", "Competidores");
    Grupo grupoContratistas (43, "GCONT", "Contratistas");

    Zona zonaSantaCruz (new Persona ("David Munoz", "6-2345-1111", 29), "Zona Santa Cruz");
    zonaSantaCruz.agregar(&grupoSocios);

    Zona zonaNicoya (new Persona ("Jason Murillo", "1-9839-2098", 28), "Zona Nicoya");
    zonaNicoya.agregar(&grupoAccionistas);

    Zona zonaChorotega (new Persona ("German Gamboa", "1-3452-0987", 33), "Zona Chorotega");
    zonaChorotega.agregar(&zonaSantaCruz);
    zonaChorotega.agregar(&zonaNicoya);

    Zona zonaGolfito (new Persona ("Juan Perez", "1-1234-0342", 35), "Zona Golfito");
    zonaGolfito.agregar(&grupoContratistas);

    Zona zonaPerezZeledon (new Persona ("Cesar Gutierrez", "1-1455-2234", 28), "Zona Perez Zeledon");
    zonaPerezZeledon.agregar(&grupoClientes);
    zonaPerezZeledon.agregar(&zonaGolfito);

    Zona zonaBrunca (new Persona ("Antonio Jesus", "1-1455-3466", 57), "Zona Brunca");
    zonaBrunca.agregar(&zonaPerezZeledon);

    Zona zonaNacional (new Persona ("Rodrigo Chavez", "1-1080-0342", 43), "Zona Nacional");
    zonaNacional.agregar(&zonaBrunca);
    zonaNacional.agregar(&grupoCompetidores);
    zonaNacional.agregar(&zonaChorotega);

    REQUIRE( zonaNacional.obtenerTotalPresupuesto() == 171000000);
}

TEST_CASE("Actividades, Presupuesto y Asociados de TODA la Zona Nacional", "[Calculo_6]"){
    Grupo grupoAccionistas (15, "GACCI", "Accionistas");
    Grupo grupoSocios (52, "GSOCI", "Socios");
    Grupo grupoTrabajadores (55, "GTRAB", "Trabajadores");
    Grupo grupoClientes (39, "GCLIE", "Clientes");
    Grupo grupoCompetidores (33, "GCOMP", "Competidores");
    Grupo grupoContratistas (43, "GCONT", "Contratistas");
    Grupo grupoMediosComunicacion (37, "GMEDI", "Medios de Comunicacion");

    Zona zonaSantaCruz (new Persona ("David Munoz", "6-2345-1111", 29), "Zona Santa Cruz");
    zonaSantaCruz.agregar(&grupoSocios);

    Zona zonaNicoya (new Persona ("Jason Murillo", "1-9839-2098", 28), "Zona Nicoya");
    zonaNicoya.agregar(&grupoAccionistas);

    Zona zonaChorotega (new Persona ("German Gamboa", "1-3452-0987", 33), "Zona Chorotega");
    zonaChorotega.agregar(&zonaSantaCruz);
    zonaChorotega.agregar(&zonaNicoya);

    Zona zonaSarapiqui (new Persona ("Maria Salguero", "1-2343-2222", 45), "Zona Sarapiqui");
    zonaSarapiqui.agregar(&grupoMediosComunicacion);
    zonaSarapiqui.agregar(&grupoTrabajadores);

    Zona zonaHuetarNorte (new Persona ("Marcela Quiros", "5-2343-2222", 34), "Zona Huetar-Norte");
    zonaHuetarNorte.agregar(&zonaSarapiqui);

    Zona zonaGolfito (new Persona ("Juan Perez", "1-1234-0342", 35), "Zona Golfito");
    zonaGolfito.agregar(&grupoContratistas);

    Zona zonaPerezZeledon (new Persona ("Cesar Gutierrez", "1-1455-2234", 28), "Zona Perez Zeledon");
    zonaPerezZeledon.agregar(&grupoClientes);
    zonaPerezZeledon.agregar(&zonaGolfito);

    Zona zonaBrunca (new Persona ("Antonio Jesus", "1-1455-3466", 57), "Zona Brunca");
    zonaBrunca.agregar(&zonaPerezZeledon);

    Zona zonaNacional (new Persona ("Rodrigo Chavez", "1-1080-0342", 43), "Zona Nacional");
    zonaNacional.agregar(&zonaBrunca);
    zonaNacional.agregar(&grupoCompetidores);
    zonaNacional.agregar(&zonaHuetarNorte);
    zonaNacional.agregar(&zonaChorotega);

    REQUIRE( zonaNacional.obtenerTotalCantActividades() == 175);
    REQUIRE( zonaNacional.obtenerTotalPresupuesto() == 201000000);
    REQUIRE( zonaNacional.obtenerTotalCantidadAsociados() == 154);
}
