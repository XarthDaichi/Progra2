//
// Created by Xarthy on 0016 June 16, 2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_GARMENT_H
#define PROGRA_PROJECT_2_DELTA_GARMENT_H

#include <ostream>
#include "Clothing.h"

class Garment : public Clothing {
protected:
    string color;
    string size;
    string type;
    bool characteristic;
public:
    Garment();

    Garment(const string &code, const string &color, const string &size, const string &type,
            bool characteristic);

    ~Garment() override;

    const string &getColor() const;

    void setColor(const string &color);

    const string &getSize() const;

    void setSize(const string &size);

    const string &getType() const;

    void setType(const string &type);

    bool isCharacteristic() const;

    void setCharacteristic(bool characteristic);

    friend ostream &operator<<(ostream &os, const Garment &garment);

    string toString() const override;

    vector<Clothing *> hasClothes() const override;

    double calculatePrice() const override;
};


#endif //PROGRA_PROJECT_2_DELTA_GARMENT_H
