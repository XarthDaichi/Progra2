//
// Created by Xarthy on 0019 May 19, 2022.
//

#ifndef ADAPTER_VIDEOGAME_H
#define ADAPTER_VIDEOGAME_H
#include <iostream>
using namespace std;

class Videogame {
private:
    double priceDollar;
    string name;
    string company;
public:
    Videogame();

    Videogame(double priceDollar, const string &name, const string &company);

    virtual ~Videogame();

    double getPriceDollar() const;

    void setPriceDollar(double priceDollar);

    const string &getName() const;

    void setName(const string &name);

    const string &getCompany() const;

    void setCompany(const string &company);

    friend ostream &operator<<(ostream &os, const Videogame &videogame);
};


#endif //ADAPTER_VIDEOGAME_H
