//
// Created by Xarthy on 0019 May 19, 2022.
//

#include "VideogameInColonObjectAdapter.h"

Videogame VideogameInColonObjectAdapter::buyVideogameInColon(double priceColon, const string &name, const string &company) {
    clog << "ADAPTER > ";
    return videogameInDollar->buyVideogame(convertColonToDollar(priceColon),name,company);
}

double VideogameInColonObjectAdapter::convertColonToDollar(double priceColon) {
    return priceColon * COLON_X_DOLLAR;
}