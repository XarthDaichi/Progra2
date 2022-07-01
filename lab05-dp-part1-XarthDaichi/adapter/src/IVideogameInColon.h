//
// Created by Xarthy on 0019 May 19, 2022.
//

#ifndef MY_PROJECT_NAME_IVIDEOGAMEINCOLON_H
#define MY_PROJECT_NAME_IVIDEOGAMEINCOLON_H

#include "Videogame.h"

class IVideogameInColon {
public:
    virtual Videogame buyVideogameInColon(double priceColon, const string &name, const string &company) = 0;

    virtual ~IVideogameInColon();
};


#endif //MY_PROJECT_NAME_IVIDEOGAMEINCOLON_H
