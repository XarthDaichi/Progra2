//
// Created by Xarthy on 0019 May 19, 2022.
//

#include "VideogameInDollar.h"

Videogame VideogameInDollar::buyVideogame(double priceDollar, const string &name, const string &company) {
    clog << "ADAPTEE |" << endl;
    cout << "Purchasing " << name  << " for $" << priceDollar << endl;
    Videogame videogame {priceDollar, name, company};
    return videogame;
}