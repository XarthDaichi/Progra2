//
// Created by ribre on 21/06/2022.
//

#include "StockData.h"

StockData::StockData() = default;

StockData::~StockData() = default;

bool StockData::registerObserver(IObserver *observer) {
    if (observers.empty()) {
        observers.push_back(observer);
        return true;
    }
    auto i = dynamic_cast<Subscriber*> (observer);
    if (i) {
        for (auto j : observers) {
            auto k = dynamic_cast<Subscriber*> (j);
            if (k) {
                if (i->getId() == k->getId()) {
                    return false;
                }
            }
        }
    }
    observers.push_back(observer);
    return true;
}

void StockData::removeObserver(IObserver *observer) {
    auto it = observers.begin();
    for(int i = 0; i < observers.size(); i++) {
        if (observers[i] == observer) {
            observers.erase(it+i);
        }
    }
}

void StockData::notifyObservers() {
    for (IObserver *observer : observers) {
        observer->update(stock, catalog);
    }
}

void StockData::loadState(Set* stock, Set* catalog){

    this->stock= stock;
    this->catalog= catalog;
    std::cout << std::endl;

    notifyObservers();
}

const vector<IObserver *> &StockData::getObservers() const {
    return observers;
}

void StockData::setObservers(const vector<IObserver *> &observers) {
    StockData::observers = observers;
}

Set *StockData::getStock() {
    return stock;
}

void StockData::setStock(Set *stock) {
    StockData::stock = stock;
}

Set *StockData::getCatalog() {
    return catalog;
}

void StockData::setCatalog(Set *catalog) {
    StockData::catalog = catalog;
}

bool StockData::observerExists(IObserver* observer) {
    Subscriber* entry = dynamic_cast<Subscriber*> (&*observer);
    if (entry) {
        for (auto * i : observers) {
            Subscriber * iSub = dynamic_cast<Subscriber*> (&*i);
            if (iSub && (iSub->getId()== entry->getId())) {
                return true;
            }
        }
    }
    return false;
}
