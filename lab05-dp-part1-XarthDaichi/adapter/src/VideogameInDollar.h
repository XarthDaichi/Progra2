//
// Created by Xarthy on 0019 May 19, 2022.
//

#ifndef MY_PROJECT_NAME_VIDEOGAMEINDOLLAR_H
#define MY_PROJECT_NAME_VIDEOGAMEINDOLLAR_H

#include "IVideogameInDollar.h"

class VideogameInDollar : public IVideogameInDollar {
public:
    Videogame buyVideogame(double priceDollar, const string &name, const string &company) override;
};


#endif //MY_PROJECT_NAME_VIDEOGAMEINDOLLAR_H
