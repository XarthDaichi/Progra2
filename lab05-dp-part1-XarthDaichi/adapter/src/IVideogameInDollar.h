//
// Created by Xarthy on 0019 May 19, 2022.
//

#ifndef MY_PROJECT_NAME_IVIDEOGAMEINDOLLAR_H
#define MY_PROJECT_NAME_IVIDEOGAMEINDOLLAR_H

#include "Videogame.h"

class IVideogameInDollar {
public:
    virtual Videogame buyVideogame(double priceDollar, const string &name, const string &company) = 0;

    virtual ~IVideogameInDollar();
};


#endif //MY_PROJECT_NAME_IVIDEOGAMEINDOLLAR_H
