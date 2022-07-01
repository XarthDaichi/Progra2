//
// Created by Xarthy on 0020 June 20, 2022.
//

#include "gtest/gtest.h"
#include "PurchaseManager.h"
#include "StockData.h"
#include "Container.h"
#include "ExecutiveFactory.h"
#include "SportFactory.h"
#include "WorkFactory.h"
#include "Client.h"
#include "Company.h"


TEST(PurchaseManagerSuite, PurhcaseTest) {
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
    StockData * stockData = new StockData();
    vector<Clothing*> catalog;
    vector<Clothing*> stock;
    catalog.push_back(suit1);
    catalog.push_back(suit2);
    catalog.push_back(suit3);
    stock.push_back(suit1);
    stock.push_back(suit3);
    stockData->loadState(new Set("5001",stock),new Set("5002",catalog));

    PurchaseManager manager(stockData, new Container<Purchase>());

    Client * buyerSub1 = new Client("Diego", "1", 9, false, "diego@temp.com");

    Company * buyerSub2 = new Company("UNA", "J1", 1, true, false);

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


    stringstream s;

    s << manager.purchase(p1);
    EXPECT_STREQ(s.str().c_str(), "--- Receipt ---\n"
                                  "buyer:  name: Diego id: 1 cart:  code: P1 price: 1390 has:  code: 4001 price: 965 has:  code: 1001 price: 315 color: Gre"
                                  "en size: Medium type: Shirt:LongSleeve characteristic: 1 -  code: 2001 price: 250 color: Blue size: Medium type: Pant:Dr"
                                  "essUp characteristic: 0 -  code: 3001 price: 400 color: White size: Medium type: Shoe:Executive characteristic: 1 -  - "
                                  " code: 4003 price: 425 has:  code: 1003 price: 150 color: White size: Small type: Shirt:WithSquares characteristic: 0 - "
                                  " code: 2003 price: 50 color: Blue size: Small type: Pant:Jeans characteristic: 0 -  code: 3003 price: 225 color: White si"
                                  "ze: Medium type: Shoe:Boots characteristic: 1 -  - \n"
                                  "\n"
                                  "Gain Cost (80%): --- 1112\n"
                                  "IVA (15%): --------- 166.8\n"
                                  "Shipping Cost: ----- 50\n"
                                  "Total: ------------- 2718.8\n");
    s.str("");
    s << manager.purchase(p2);
    EXPECT_STREQ(s.str().c_str(), "--- Receipt ---\n"
                                  "buyer:  name: UNA id: J1 cart:  code: P2 price: 1965 has:  code: 4001 price: 965 has:  code: 1001 price: 315 color: Gree"
                                  "n size: Medium type: Shirt:LongSleeve characteristic: 1 -  code: 2001 price: 250 color: Blue size: Medium type: Pant:Dre"
                                  "ssUp characteristic: 0 -  code: 3001 price: 400 color: White size: Medium type: Shoe:Executive characteristic: 1 -  -  c"
                                  "ode: 4002 price: 575 has:  code: 1002 price: 200 color: Red size: Large type: Shirt:T-shirt characteristic: 1 -  code: 2"
                                  "002 price: 150 color: Black size: Large type: Pant:Shorts characteristic: 1 -  code: 3002 price: 225 color: Red size: La"
                                  "rge type: Shoe:Tennis characteristic: 0 -  -  code: 4003 price: 425 has:  code: 1003 price: 150 color: White size: Small"
                                  " type: Shirt:WithSquares characteristic: 0 -  code: 2003 price: 50 color: Blue size: Small type: Pant:Jeans characterist"
                                  "ic: 0 -  code: 3003 price: 225 color: White size: Medium type: Shoe:Boots characteristic: 1 -  - \n"
                                  "\n"
                                  "Gain Cost (80%): --- 1572\n"
                                  "IVA (15%): --------- 235.8\n"
                                  "Shipping Cost: ----- 100\n"
                                  "Total: ------------- 3872.8\n");
    s.str("");
    s << manager.purchase(p1);

    EXPECT_STREQ(s.str().c_str(), "Could not verify purchase\n");

    EXPECT_EQ(stockData->getStock()->hasClothes().size(), 0);
}

TEST(PurchaseManagerSuite, BaseSaleTest) {
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
    StockData * stockData = new StockData();
    vector<Clothing*> catalog;
    vector<Clothing*> stock;
    catalog.push_back(suit1);
    catalog.push_back(suit2);
    catalog.push_back(suit3);
    stock.push_back(suit1);
    stock.push_back(suit3);
    stockData->loadState(new Set("5001",stock),new Set("5002",catalog));

    PurchaseManager manager(stockData, new Container<Purchase>());

    Client * buyerSub1 = new Client("Diego", "1", 9, false, "diego@temp.com");

    Company * buyerSub2 = new Company("UNA", "J1", 1, true, false);

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

    manager.purchase(p1);
    manager.purchase(p2);
    manager.purchase(p1);

    EXPECT_EQ(manager.baseSale(), 3355);
}

TEST(PurchaseManagerSuite, GainSaleTest) {
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
    StockData * stockData = new StockData();
    vector<Clothing*> catalog;
    vector<Clothing*> stock;
    catalog.push_back(suit1);
    catalog.push_back(suit2);
    catalog.push_back(suit3);
    stock.push_back(suit1);
    stock.push_back(suit3);
    stockData->loadState(new Set("5001",stock),new Set("5002",catalog));

    PurchaseManager manager(stockData, new Container<Purchase>());

    Client * buyerSub1 = new Client("Diego", "1", 9, false, "diego@temp.com");

    Company * buyerSub2 = new Company("UNA", "J1", 1, true, false);

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

    manager.purchase(p1);
    manager.purchase(p2);
    manager.purchase(p1);

    EXPECT_EQ(manager.gainSale(), 6039);
}

TEST(PurchaseManagerSuite, NetGainTest) {
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
    StockData * stockData = new StockData();
    vector<Clothing*> catalog;
    vector<Clothing*> stock;
    catalog.push_back(suit1);
    catalog.push_back(suit2);
    catalog.push_back(suit3);
    stock.push_back(suit1);
    stock.push_back(suit3);
    stockData->loadState(new Set("5001",stock),new Set("5002",catalog));

    PurchaseManager manager(stockData, new Container<Purchase>());

    Client * buyerSub1 = new Client("Diego", "1", 9, false, "diego@temp.com");

    Company * buyerSub2 = new Company("UNA", "J1", 1, true, false);

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

    manager.purchase(p1);
    manager.purchase(p2);
    manager.purchase(p1);

    EXPECT_EQ(manager.netGain(), 2684);
}

TEST(PurchaseManagerSuite, mostBought) {
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
    StockData * stockData = new StockData();
    vector<Clothing*> catalog;
    vector<Clothing*> stock;
    catalog.push_back(suit1);
    catalog.push_back(suit2);
    catalog.push_back(suit3);
    stock.push_back(suit1);
    stock.push_back(suit3);
    stockData->loadState(new Set("5001",stock),new Set("5002",catalog));

    PurchaseManager manager(stockData, new Container<Purchase>());

    Client * buyerSub1 = new Client("Diego", "1", 9, false, "diego@temp.com");

    Company * buyerSub2 = new Company("UNA", "J1", 1, true, false);

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

    manager.purchase(p1);
    manager.purchase(p2);
    manager.purchase(p1);

    stringstream s;
    s << manager.mostBought();
    EXPECT_STREQ(s.str().c_str(), " code: 4001 price: 965 has:  code: 1001 price: 315 color: Green size: Medium type: Shirt:LongSleeve characteristic: 1 - "
                                  " code: 2001 price: 250 color: Blue size: Medium type: Pant:DressUp characteristic: 0 -  code: 3001 price: 400 color: Whi"
                                  "te size: Medium type: Shoe:Executive characteristic: 1 - \n"
                                  " code: 4003 price: 425 has:  code: 1003 price: 150 color: White size: Small type: Shirt:WithSquares characteristic: 0 - "
                                  " code: 2003 price: 50 color: Blue size: Small type: Pant:Jeans characteristic: 0 -  code: 3003 price: 225 color: White s"
                                  "ize: Medium type: Shoe:Boots characteristic: 1 - \n");
}