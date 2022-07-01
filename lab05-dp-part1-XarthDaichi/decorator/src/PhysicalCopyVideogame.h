//
// Created by Xarthy on 0020 May 20, 2022.
//

#ifndef DECORATOR_PHYSICALCOPYVIDEOGAME_H
#define DECORATOR_PHYSICALCOPYVIDEOGAME_H

#include <ostream>
#include "Videogame.h"

class PhysicalCopyVideogame : public Videogame {
private:
    string seller;
public:
    PhysicalCopyVideogame();

    PhysicalCopyVideogame(const string &name, const string &company, double price, const string &seller);

    const string &getSeller() const;

    void setSeller(const string &seller);

    friend ostream &operator<<(ostream &os, const PhysicalCopyVideogame &videogame);
};


#endif //DECORATOR_PHYSICALCOPYVIDEOGAME_H
