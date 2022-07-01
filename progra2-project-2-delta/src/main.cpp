//
// Created by ribre on 01/06/2022.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "Subscriber.h"
#include "ExecutiveFactory.h"
#include "SportFactory.h"
#include "WorkFactory.h"
#include "Client.h"
#include "Company.h"
#include "Garment.h"
#include "Suit.h"
#include "Set.h"
#include "PurchaseManager.h"
#include "PurchaseFileManager.h"
#include "StockFilemanager.h"
#include "StockData.h"
#include "Container.h"
#include <stdexcept>
using namespace std;

void generateFiles() {
    IClothingFactory* factory = new ExecutiveFactory;
    Clothing* shirt1 = dynamic_cast<Clothing*> (factory->createShirt("1001","Green","Medium",true));
    Clothing* pant1 = dynamic_cast<Clothing*> (factory->createPant("2001","Blue","Medium",false));
    Clothing* shoe1 = dynamic_cast<Clothing*> (factory->createShoe("3001","White","Medium",true));
    vector<Clothing*> vec1;
    vec1.push_back(shirt1);
    vec1.push_back(pant1);
    vec1.push_back(shoe1);

    factory = new SportFactory;
    Clothing* shirt2 = dynamic_cast<Clothing*> (factory->createShirt("1002","Red","Large",true));
    Clothing* pant2 = dynamic_cast<Clothing*> (factory->createPant("2002","Black","Large",true));
    Clothing* shoe2 = dynamic_cast<Clothing*> (factory->createShoe("3002","Red","Large",false));
    vector<Clothing*> vec2;
    vec2.push_back(shirt2);
    vec2.push_back(pant2);
    vec2.push_back(shoe2);

    factory = new WorkFactory;
    Clothing* shirt3 = dynamic_cast<Clothing*> (factory->createShirt("1003","White","Small",false));
    Clothing* pant3 = dynamic_cast<Clothing*> (factory->createPant("2003","Blue","Small",false));
    Clothing* shoe3 = dynamic_cast<Clothing*> (factory->createShoe("3003","White","Medium",true));
    vector<Clothing*> vec3;
    vec3.push_back(shirt3);
    vec3.push_back(pant3);
    vec3.push_back(shoe3);

    Clothing* suit1 = dynamic_cast<Clothing*> (factory->createSuit("4001",vec1));
    Clothing* suit2 = dynamic_cast<Clothing*> (factory->createSuit("4002",vec2));
    Clothing* suit3 = dynamic_cast<Clothing*> (factory->createSuit("4003",vec3));
    StockData stockData;
    vector<Clothing*> catalog;
    vector<Clothing*> stock;
    catalog.push_back(suit1);
    catalog.push_back(suit2);
    catalog.push_back(suit3);
    stock.push_back(suit1);
    stock.push_back(suit3);
    stockData.loadState(new Set("5001",stock),new Set("5002",catalog));

    ofstream out("../../db_stockdata.dat", ios::trunc | ios::out | ios::binary);
//    if (!out.is_open()) throw invalid_argument("Could not open file [../../db_stockdata.dat]");

    out.write((char*)&stockData, sizeof(stockData));

    out.close();

    out.open("../../db_purchase.dat", ios::trunc | ios::out | ios::binary);
    out.close();

//    StockFileManager::getInstance().setInfo(&stockData);
}

int main() {
    try {
        generateFiles();

        PurchaseManager * buyer = new PurchaseManager(StockFileManager::getInstance().getInfo(), PurchaseFileManager::getInstance().getPurchases());


        cout << "---------- Original catalog and stock and observers -----------" << endl << endl;
        for (auto * i : StockFileManager::getInstance().getInfo()->getObservers()) {
            Subscriber * iSub = dynamic_cast<Subscriber *> (&*i);
            cout << *iSub  << " --- ";
        }
        cout << endl << endl;
        cout << *StockFileManager::getInstance().getInfo()->getCatalog() << endl << endl;
        cout << *StockFileManager::getInstance().getInfo()->getStock() << endl << endl;

        Client * buyerSub1 = new Client("Diego", "1", 9, false, "diego@temp.com");

        Company * buyerSub2 = new Company("UNA", "J1", 1, true, false);

        IClothingFactory* factory = new ExecutiveFactory;
        Clothing* shirt1 = dynamic_cast<Clothing*> (factory->createShirt("1001","Green","Medium",true));
        Clothing* pant1 = dynamic_cast<Clothing*> (factory->createPant("2001","Blue","Medium",false));
        Clothing* shoe1 = dynamic_cast<Clothing*> (factory->createShoe("3001","White","Medium",true));
        vector<Clothing*> vec1;
        vec1.push_back(shirt1);
        vec1.push_back(pant1);
        vec1.push_back(shoe1);

        factory = new SportFactory;
        Clothing* shirt2 = dynamic_cast<Clothing*> (factory->createShirt("1002","Red","Large",true));
        Clothing* pant2 = dynamic_cast<Clothing*> (factory->createPant("2002","Black","Large",true));
        Clothing* shoe2 = dynamic_cast<Clothing*> (factory->createShoe("3002","Red","Large",false));
        vector<Clothing*> vec2;
        vec2.push_back(shirt2);
        vec2.push_back(pant2);
        vec2.push_back(shoe2);

        factory = new WorkFactory;
        Clothing* shirt3 = dynamic_cast<Clothing*> (factory->createShirt("1003","White","Small",false));
        Clothing* pant3 = dynamic_cast<Clothing*> (factory->createPant("2003","Blue","Small",false));
        Clothing* shoe3 = dynamic_cast<Clothing*> (factory->createShoe("3003","White","Medium",true));
        vector<Clothing*> vec3;
        vec3.push_back(shirt3);
        vec3.push_back(pant3);
        vec3.push_back(shoe3);


        Clothing* suit1 = dynamic_cast<Clothing*> (factory->createSuit("4001",vec1));
        Clothing* suit2 = dynamic_cast<Clothing*> (factory->createSuit("4002",vec2));
        Clothing* suit3 = dynamic_cast<Clothing*> (factory->createSuit("4003",vec3));

        Set * set1 = new Set();
        set1->setCode("P1");
        set1->add(suit1);
        set1->add(suit3);
        Purchase * p1 = new Purchase(set1, buyerSub1);

        Set * set2 = new Set();
        set2->setCode("P2");
        set2->add(suit1);
        set2->add(suit2);
        set2->add(suit3);
        Purchase * p2 = new Purchase(set2, buyerSub2);

        cout << buyer->purchase(p1) << endl;
        cout << buyer->purchase(p2) << endl;
        cout << buyer->purchase(p1) << endl;


        cout << "------- Modified catalog and stock and observers-----------------" << endl << endl;
        for (auto * i : StockFileManager::getInstance().getInfo()->getObservers()) {
            Subscriber * iSub = dynamic_cast<Subscriber *> (&*i);
            cout << *iSub  << " --- ";
        }
        cout << endl << endl;

        cout << *StockFileManager::getInstance().getInfo()->getCatalog() << endl << endl;

        cout << *StockFileManager::getInstance().getInfo()->getStock() << endl;

        cout << "----------- Purchase Register -----" << endl;
        for(auto * i : PurchaseFileManager::getInstance().getPurchases()->allObjects()) {
            cout << *i << endl;
        }
//        cout << "----------- Most bought -----" << endl;
//        cout << buyer->mostBought() << endl;
    } catch(std::exception& ex) {
        std::cerr << ex.what() << '\n' << std::endl;
    }
    return 0;
}

