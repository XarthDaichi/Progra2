//
// Created by Xarthy on 0020 May 20, 2022.
//

#ifndef DECORATOR_DIGITALCOPYVIDEOGAME_H
#define DECORATOR_DIGITALCOPYVIDEOGAME_H

#include <ostream>
#include "Videogame.h"

class DigitalCopyVideogame : public Videogame {
private:
    string onlineRetailer;
public:
    DigitalCopyVideogame();

    DigitalCopyVideogame(const string &name, const string &company, double price, const string &onlineRetailer);

    virtual ~DigitalCopyVideogame();

    const string &getOnlineRetailer() const;

    void setOnlineRetailer(const string &onlineRetailer);

    friend ostream &operator<<(ostream &os, const DigitalCopyVideogame &videogame);
};


#endif //DECORATOR_DIGITALCOPYVIDEOGAME_H
