//
// Created by Xarthy on 0020 May 20, 2022.
//

#ifndef DECORATOR_VIDEOGAME_H
#define DECORATOR_VIDEOGAME_H

#include <iostream>
using namespace std;

class Videogame {
private:
    string name;
    string company;
    double price;
public:
    Videogame();

    Videogame(const string &name, const string &company, double price);

    virtual ~Videogame();

    const string &getName() const;

    void setName(const string &name);

    const string &getCompany() const;

    void setCompany(const string &company);

    double getPrice() const;

    void setPrice(double price);

    friend ostream &operator<<(ostream &os, const Videogame &videogame);
};


#endif //DECORATOR_VIDEOGAME_H
