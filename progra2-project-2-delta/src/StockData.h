//
// Created by ribre on 21/06/2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_STOCKDATA_H
#define PROGRA_PROJECT_2_DELTA_STOCKDATA_H

#include <ostream>
#include <iostream>
#include <vector>
#include "IObserver.h"
#include "ISubject.h"
#include "Set.h"
#include "Subscriber.h"

using namespace std;

class StockData: public ISubject {
private:
    vector<IObserver *> observers;
    Set * stock{};
    Set * catalog{};
public:
    StockData();

    ~StockData() override;

    bool registerObserver(IObserver *observer) override;

    void removeObserver(IObserver *observer) override;

    void notifyObservers() override;

    void loadState(Set* stock, Set* catalog);

    const vector<IObserver *> &getObservers() const;

    void setObservers(const vector<IObserver *> &observers);

    Set *getStock();

    void setStock(Set *stock);

    Set *getCatalog();

    void setCatalog(Set *catalog);

    bool observerExists(IObserver * observer);
};


#endif //PROGRA_PROJECT_2_DELTA_STOCKDATA_H
