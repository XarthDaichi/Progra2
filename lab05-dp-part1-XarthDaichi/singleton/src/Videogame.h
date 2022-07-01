//
// Created by Xarthy on 0021 May 21, 2022.
//

#ifndef SINGLETON_VIDEOGAME_H
#define SINGLETON_VIDEOGAME_H

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


#endif //SINGLETON_VIDEOGAME_H
