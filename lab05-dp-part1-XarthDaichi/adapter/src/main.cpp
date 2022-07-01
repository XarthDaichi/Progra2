//
// Created by Xarthy on 0017 May 17, 2022.
//

#include <iostream>
#include "IVideogameInColon.h"
#include "VideogameInColonObjectAdapter.h"
#include "VideogameInColonClassAdapter.h"


int main() {
    clog << "CLIENT > TARGET (IVideogameInDollar)" << endl;
    IVideogameInDollar *normalClient = new VideogameInDollar;
    normalClient->buyVideogame(39.99, "Star Wars Jedi: Fallen Order Deluxe Edition", "Respawn Entertainment");
    normalClient->buyVideogame(15.99,"Hollow Knight", "Team Cherry");

    clog << "CLIENT > TARGET (IVideogameInColon)" << endl;
    cout << "Implementation with [Class Adapter]" << endl;
    IVideogameInColon *adapterClassInterface = new VideogameInColonClassAdapter;
    adapterClassInterface->buyVideogameInColon(29000.00, "Star Wars Jedi: Fallen Order Deluxe Edition", "Respawn Entertainment");
    adapterClassInterface->buyVideogameInColon(6500.00, "Hollow Knight", "Team Cherry");

    clog << "CLIENT > TARGET (IVideogameInColon)" << endl;
    cout << endl << "Implementation with [Object Adapter] " << endl;
    IVideogameInColon *adapterObjectInterface = new VideogameInColonObjectAdapter;
    adapterObjectInterface->buyVideogameInColon(29000.00, "Star Wars Jedi: Fallen Order Deluxe Edition", "Respawn Entertainment");
    adapterObjectInterface->buyVideogameInColon(6500.00, "Hollow Knight", "Team Cherry");
    return 0;
}