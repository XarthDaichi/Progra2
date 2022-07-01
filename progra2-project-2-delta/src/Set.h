//
// Created by Xarthy on 0016 June 16, 2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_SET_H
#define PROGRA_PROJECT_2_DELTA_SET_H

#include <ostream>
#include "Clothing.h"
#include "ISet.h"

class Set
        : public Clothing, public ISet {
private:
    vector<Clothing *> has;
public:
    Set();

    Set(const string &code, const vector<Clothing *> &has);

    ~Set() override;

    void setHas(const vector<Clothing *> &has);

    friend ostream &operator<<(ostream &os, const Set &set);

    string toString() const override;

    void add(Clothing *clothing) override;

    void remove(Clothing *clothing) override;

    vector<Clothing *> hasClothes() const override;

    double calculatePrice() const override;

    Garment *SearchGarment(string string1) override;
};


#endif //PROGRA_PROJECT_2_DELTA_SET_H
