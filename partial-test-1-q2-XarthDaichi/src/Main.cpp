//
// Created by Maikol Guzman on 3/18/22.
//
#include <iostream>
#include "Policia.h"
#include "Robot.h"
#include "RoboCop.h"
#include "Guerrero.h"
#include "Humanoide.h"
#include "HumanoideManager.h"
#include "Armadura.h"
#include "Alien.h"
#include "Predator.h"
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    cout << "Bienvenidos a la Universidad Nacional! (VIRTUAL)" << endl;
    cout << "Primer examen parcial - Parte #2" << endl << endl;

    cout << "Este es el test de Policia" << endl;
    Policia policia;
    policia.setNombre("Policia Especial");

    stringstream toString;
    toString << policia;

    if ( toString.str() == "[Policia] nombre: Policia Especial") cout << "POLICIA ToSTRING TURE" << endl;
    else cout << "POLICIA ToSTRING FALSE" << endl;
    if( policia.aprende() == "Aprendo como un policia." ) cout << "POLICIA APRENDE TRUE" << endl;
    else cout << "POLICIA APRENDE FALSE" << endl;
    if( policia.aplicaJusticia() == "Aplico la justicia como un policia." ) cout << "POLICIA APLICA JUSTICIA TRUE" << endl;
    else cout << "POLICIA APLICA JUSTICA FLASE" << endl;
    if( policia.ayuda() == "Ayudo a la gente como a un policia." ) cout << "POLICIA AYUDA TRUE" << endl;
    else cout << "POLICIA AYUDA FALSE" << endl;


//    cout << "Este es el test de Robot" << endl;
//    Robot robot;
//
//    stringstream toString;
//    toString << robot;
//
//    if( toString.str() == "[Robot] nivelDeBateria: 100, numSensores: 2000") cout << "ROBOT ToSTRING TRUE" << endl;
//    else cout << "ROBOT ToSTRING FALSE" << endl;
//    ( robot.getNivelDeBateria() == 100 );
//    REQUIRE( robot.getNumSensores() == 2000 );
//    REQUIRE( robot.seConfigura() == "Yo, como robot me puedo configurar.");
//    REQUIRE( robot.seRecarga() == "Yo, como robot busco como recargar la bateria");

    return 0;
}
