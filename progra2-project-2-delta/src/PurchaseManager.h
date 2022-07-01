//
// Created by Xarthy on 0022 June 22, 2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_PURCHASEMANAGER_H
#define PROGRA_PROJECT_2_DELTA_PURCHASEMANAGER_H
#include "StockData.h"
#include "Purchase.h"
#include "Container.h"

class PurchaseManager {
private:
    StockData * info;
    Container<Purchase> * purchases;
public:
    PurchaseManager(StockData *info, Container<Purchase> *purchases);

    virtual ~PurchaseManager();

    bool exists(Clothing*);

    bool available(Clothing*);

    string mostBought() const;

    double baseSale() const;

    double gainSale() const;

    double netGain() const;

    bool verifyPurchase(Purchase*);

    string purchase(Purchase*);
};


#endif //PROGRA_PROJECT_2_DELTA_PURCHASEMANAGER_H
