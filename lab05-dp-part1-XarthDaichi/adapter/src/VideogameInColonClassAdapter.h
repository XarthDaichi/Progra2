//
// Created by Xarthy on 0019 May 19, 2022.
//

#ifndef MY_PROJECT_NAME_VIDEOGAMEINCOLONCLASSADAPTER_H
#define MY_PROJECT_NAME_VIDEOGAMEINCOLONCLASSADAPTER_H
#include "IVideogameInDollar.h"
#include "IVideogameInColon.h"
#include "VideogameInDollar.h"



class VideogameInColonClassAdapter : public  VideogameInDollar, public IVideogameInColon {
public:
    double COLON_X_DOLLAR = 0.0015;
    Videogame buyVideogameInColon(double priceColon, const string &name, const string &company);
    double convertColonToDollar(double priceColon);
};


#endif //MY_PROJECT_NAME_VIDEOGAMEINCOLONCLASSADAPTER_H
