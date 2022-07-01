//
// Created by Xarthy on 0022 June 22, 2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_PURCHASE_H
#define PROGRA_PROJECT_2_DELTA_PURCHASE_H

#include <ostream>
#include "Set.h"
#include "Garment.h"
#include "Suit.h"
#include "StockData.h"
#include "Subscriber.h"

class Purchase : public Object {
private:
    Set * cart{};
    Subscriber * buyer{};
public:
    Purchase();

    Purchase(Set *cart, Subscriber *buyer);

    ~Purchase() override;

    Set *getCart() const;

    void setCart(Set *cart);

    Subscriber *getBuyer() const;

    void setBuyer(Subscriber *buyer);

    friend ostream &operator<<(ostream &os, const Purchase &purchase);

    string toString() const override;
};


#endif //PROGRA_PROJECT_2_DELTA_PURCHASE_H
