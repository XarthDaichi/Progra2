//
// Created by Xarthy on 0020 May 20, 2022.
//

#ifndef DECORATOR_DISCOUNTEDVIDEOGAME_H
#define DECORATOR_DISCOUNTEDVIDEOGAME_H

#include <ostream>
#include "Videogame.h"

class DiscountedVideogame : public Videogame {
private:
    const Videogame& videogame;
    double discount;
public:
    DiscountedVideogame(const Videogame &videogame, double discount);

    virtual ~DiscountedVideogame();

    const Videogame &getVideogame() const;

    double getDiscount() const;

    void setDiscount(double discount);

    friend ostream &operator<<(ostream &os, const DiscountedVideogame &videogame);
};


#endif //DECORATOR_DISCOUNTEDVIDEOGAME_H
