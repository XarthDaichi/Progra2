//
// Created by Xarthy on 0016 June 16, 2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_SUIT_H
#define PROGRA_PROJECT_2_DELTA_SUIT_H

#include <ostream>
#include "Clothing.h"
#include "ISuit.h"

class Suit
        : public Clothing, public ISuit {
private:
    string type;
    vector<Clothing *> has;
public:
    Suit();

    Suit(const string &code, const string &type, const vector<Clothing *> &has);

    ~Suit() override;

    void setHas(const vector<Clothing *> &has);

    const string &getType() const;

    void setType(const string &type);

    friend ostream &operator<<(ostream &os, const Suit &suit);

    string toString() const override;

    void add(Clothing *clothing) override;

    void remove(Clothing *clothing) override;

    vector<Clothing *> hasClothes() const override;

    double calculatePrice() const override;

    Garment *SearchGarment(string) override;
};


#endif //PROGRA_PROJECT_2_DELTA_SUIT_H
