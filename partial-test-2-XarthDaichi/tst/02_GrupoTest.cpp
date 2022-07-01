//
// Created by Maikol Guzman Alan on 4/8/22.
//

#include "../src/Grupo.h"
#include "../lib/catch2/catch.hpp"

// Descomentar el bloque siguiente para autoevaluación, la ejecución correcta de esta prueba le genera los puntos
// Valor total de este Ejercicio: 5 pts
// Hacer commit de la prueba sin el bloque comentado

TEST_CASE("Verificación del constructor del grupo", "[Grupo_1]"){
    Grupo grupoAccionistas (15, "GACCI", "Accionistas");

    REQUIRE( grupoAccionistas.getNombreGrupo() == "Accionistas");
    REQUIRE( grupoAccionistas.obtenerTotalPresupuesto() == 33000000);
    REQUIRE( grupoAccionistas.obtenerTotalCantActividades() == 30);
}

TEST_CASE("toString() de Grupo", "[Grupo_2]"){
    Grupo grupoSocios;
    grupoSocios.setCodigo(52);
    grupoSocios.setCodigoGrupo("GSOCI");
    grupoSocios.setNombreGrupo("Socios");

    REQUIRE( grupoSocios.toString() == "presupuesto: 39000000 cantidadDeActividades: 35 cantidadDeAsociados: 22 codigo: 52 codigoGrupo: GSOCI nombreGrupo: Socios");
}
