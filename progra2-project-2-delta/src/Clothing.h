//
// Created by Xarthy on 0016 June 16, 2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_CLOTHING_H
#define PROGRA_PROJECT_2_DELTA_CLOTHING_H

#include "Object.h"
#include "PricingManager.h"
#include <vector>
#include <ostream>

class Clothing : public Object {
protected:
    double price{};
    string code;
public:
    Clothing();

    Clothing(const string &code);

    virtual ~Clothing();

    double getPrice() const;

    void setPrice(double price);

    const string &getCode() const;

    void setCode(const string &code);

    friend ostream &operator<<(ostream &os, const Clothing &clothing);

    string toString() const override = 0;

    virtual void add(Clothing *clothing);
    virtual void remove(Clothing *clothing);
    virtual vector<Clothing *> hasClothes() const = 0;
    virtual double calculatePrice() const = 0;
};


#endif //PROGRA_PROJECT_2_DELTA_CLOTHING_H
