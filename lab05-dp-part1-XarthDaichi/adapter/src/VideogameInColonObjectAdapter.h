//
// Created by Xarthy on 0019 May 19, 2022.
//

#ifndef MY_PROJECT_NAME_VIDEOGAMEINCOLONOBJECTADAPTER_H
#define MY_PROJECT_NAME_VIDEOGAMEINCOLONOBJECTADAPTER_H
#include "IVideogameInColon.h"
#include "IVideogameInDollar.h"
#include "VideogameInDollar.h"

class VideogameInColonObjectAdapter : public IVideogameInColon {
private:
    IVideogameInDollar *videogameInDollar = new VideogameInDollar();
public:
    double COLON_X_DOLLAR = 0.0015;
    Videogame buyVideogameInColon(double priceDollar, const string &name, const string &company) override;
    double convertColonToDollar(double priceColon);
};


#endif //MY_PROJECT_NAME_VIDEOGAMEINCOLONOBJECTADAPTER_H
