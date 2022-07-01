//
// Created by Xarthy on 0019 May 19, 2022.
//

#include "VideogameInColonClassAdapter.h"

Videogame VideogameInColonClassAdapter::buyVideogameInColon(double priceColon, const string &name, const string &company) {
    clog << "ADAPTER > ";
    return VideogameInDollar::buyVideogame(convertColonToDollar(priceColon), name, company);
}

double VideogameInColonClassAdapter::convertColonToDollar(double priceColon) {
    return priceColon * COLON_X_DOLLAR;
}