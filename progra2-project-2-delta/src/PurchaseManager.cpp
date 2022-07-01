//
// Created by Xarthy on 0022 June 22, 2022.
//

#include "PurchaseManager.h"

PurchaseManager::PurchaseManager(StockData *info, Container<Purchase> *purchases) : info(info), purchases(purchases) {}

PurchaseManager::~PurchaseManager() {

}

bool PurchaseManager::exists(Clothing* search) {
    for (auto * i : info->getCatalog()->hasClothes()) {
        if (search->getCode() == i->getCode())
            return true;
    }
    return false;
}

bool PurchaseManager::available(Clothing* search) {
    for (auto * i : info->getStock()->hasClothes()) {
        if (search->getCode() == i->getCode()) {
            return true;
        }
    }
    return false;
}

string PurchaseManager::mostBought() const {
    int mostCounter = 0;
    vector<Clothing*> mostItem;
    for (auto * i : info->getCatalog()->hasClothes()) {
        int tempCounter = purchases->certainObjects(*i).size();
        if (tempCounter > mostCounter) {
            mostItem.clear();
            mostItem.push_back(i);
            mostCounter = tempCounter;
        } else if (tempCounter == mostCounter) {
            mostItem.push_back(i);
        }
    }
    stringstream s;
    for (auto * i : mostItem) {
        Suit * iSuit = dynamic_cast<Suit *> (&*i);
        if (iSuit) s << *iSuit << endl;
        else {
            Garment * iGar = dynamic_cast<Garment *> (&*i);
            if (iGar) s << *iGar << endl;
        }
    }
    return s.str();
}

double PurchaseManager::baseSale() const {
    double sum = 0;
    for(auto * i : purchases->allObjects()) {
        sum += i->getCart()->getPrice();
    }
    return sum;
}

double PurchaseManager::gainSale() const {
    return baseSale() * 1.80;
}

double PurchaseManager::netGain() const {
    return gainSale() - baseSale();
}

bool PurchaseManager::verifyPurchase(Purchase* entry) {
    if (!info->observerExists(entry->getBuyer())) info->registerObserver(entry->getBuyer());

    for (auto * i : entry->getCart()->hasClothes()) {
        if (!entry->getBuyer()->isOnline() && !(exists(i) && available(i))) return false;
        else if (!exists(i)) return false;
        if (available(i)) info->getStock()->remove(i);
    }
    purchases->push(entry);
    return true;
}

string PurchaseManager::purchase(Purchase* entry) {
    stringstream s;
    if (verifyPurchase(entry)) {
        clog << "Made Purchase" << endl;
        s << "--- Receipt ---" << endl
        << *entry << endl << endl;
        s << "Gain Cost (80%): --- " << entry->getCart()->getPrice() * 0.80 << endl
        << "IVA (15%): --------- " << entry->getCart()->getPrice() * 0.80 * 0.15 << endl
        << "Shipping Cost: ----- " << entry->getBuyer()->getSendCost() << endl
        << "Total: ------------- " << entry->getCart()->getPrice() + entry->getCart()->getPrice() * 0.80 + entry->getCart()->getPrice() * 0.80*0.15 + entry->getBuyer()->getSendCost() << endl;
    } else {
        clog << "Failed verification" << endl;
        s << "Could not verify purchase" << endl;
    }

    return s.str();
}


