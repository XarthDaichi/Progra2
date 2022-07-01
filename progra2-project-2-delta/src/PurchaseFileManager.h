//
// Created by Xarthy on 0020 June 20, 2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_PURCHASEFILEMANAGER_H
#define PROGRA_PROJECT_2_DELTA_PURCHASEFILEMANAGER_H
#include "SingletonFileManager.h"
#include "Purchase.h"

class PurchaseFileManager final : public SingletonFileManager<PurchaseFileManager> {
private:
    Container<Purchase> * purchases;
    char inputType;
public:
    PurchaseFileManager(const char c = 'b');
    virtual ~PurchaseFileManager();

    Container<Purchase> *getPurchases();
};


#endif //PROGRA_PROJECT_2_DELTA_PURCHASEFILEMANAGER_H
