//
// Created by Xarthy on 0020 June 20, 2022.
//

#include "gtest/gtest.h"
#include "../src/ExecutiveFactory.h"
#include "../src/SportFactory.h"
#include "../src/WorkFactory.h"
using namespace std;

TEST(FactoryTestSuite, ExecutiveFactoryTest) {
    IClothingFactory* factory = new ExecutiveFactory;
    bool exists;

    IGarment* IShirt = factory->createShirt("1001","Green","Medium",true);
    IGarment* IPant = factory->createPant("2001","Blue","Medium",false);
    IGarment* IShoe = factory->createShoe("3001","Green","Medium",true);
    auto* shirt = dynamic_cast<Garment*> (IShirt);
    exists = shirt;
    EXPECT_TRUE(exists);
    auto* pant = dynamic_cast<Garment*> (IPant);
    exists = pant;
    EXPECT_TRUE(exists);
    auto* shoe = dynamic_cast<Garment*> (IShoe);
    exists = shoe;
    EXPECT_TRUE(exists);

    EXPECT_EQ(IShirt->showCharacteristic(), "Plain: Yes");
    EXPECT_EQ(IPant->showCharacteristic(), "Casimir: No");
    EXPECT_EQ(IShoe->showCharacteristic(), "Fine: Yes");

    vector<Clothing*> has1;
    has1.push_back(shirt);
    has1.push_back(pant);
    has1.push_back(shoe);

    ISuit* ISuit = factory->createSuit("4001",has1);
    auto* suit = dynamic_cast<Suit*> (ISuit);
    exists = suit;
    EXPECT_TRUE(exists);

    vector<Clothing*> has2;
    has2.push_back(suit);

    ISet* ISet = factory->createSet("5001",has2);
    auto* set = dynamic_cast<Set*> (ISet);
    exists = set;
    EXPECT_TRUE(exists);
}

TEST(FactoryTestSuite, WorkFactoryTest) {
    IClothingFactory* factory = new WorkFactory;
    bool exists;

    IGarment* IShirt = factory->createShirt("1001","Green","Medium",true);
    IGarment* IPant = factory->createPant("2001","Blue","Medium",false);
    IGarment* IShoe = factory->createShoe("3001","Green","Medium",true);
    auto* shirt = dynamic_cast<Garment*> (IShirt);
    exists = shirt;
    EXPECT_TRUE(exists);
    auto* pant = dynamic_cast<Garment*> (IPant);
    exists = pant;
    EXPECT_TRUE(exists);
    auto* shoe = dynamic_cast<Garment*> (IShoe);
    exists = shoe;
    EXPECT_TRUE(exists);

    EXPECT_EQ(IShirt->showCharacteristic(), "Big squares: Yes");
    EXPECT_EQ(IPant->showCharacteristic(), "Tight: No");
    EXPECT_EQ(IShoe->showCharacteristic(), "High: Yes");

    vector<Clothing*> has1;
    has1.push_back(shirt);
    has1.push_back(pant);
    has1.push_back(shoe);

    ISuit* ISuit = factory->createSuit("4001",has1);
    auto* suit = dynamic_cast<Suit*> (ISuit);
    exists = suit;
    EXPECT_TRUE(exists);

    vector<Clothing*> has2;
    has2.push_back(suit);

    ISet* ISet = factory->createSet("5001",has2);
    auto* set = dynamic_cast<Set*> (ISet);
    exists = set;
    EXPECT_TRUE(exists);
}

TEST(FactoryTestSuite, SportFactoryTest) {
    IClothingFactory* factory = new SportFactory;
    bool exists;

    IGarment* IShirt = factory->createShirt("1001","Green","Medium",true);
    IGarment* IPant = factory->createPant("2001","Blue","Medium",false);
    IGarment* IShoe = factory->createShoe("3001","Green","Medium",true);
    auto* shirt = dynamic_cast<Garment*> (IShirt);
    exists = shirt;
    EXPECT_TRUE(exists);
    auto* pant = dynamic_cast<Garment*> (IPant);
    exists = pant;
    EXPECT_TRUE(exists);
    auto* shoe = dynamic_cast<Garment*> (IShoe);
    exists = shoe;
    EXPECT_TRUE(exists);

    EXPECT_EQ(IShirt->showCharacteristic(), "V-neck: Yes");
    EXPECT_EQ(IPant->showCharacteristic(), "Stamped: No");
    EXPECT_EQ(IShoe->showCharacteristic(), "Adidas: Yes");

    vector<Clothing*> has1;
    has1.push_back(shirt);
    has1.push_back(pant);
    has1.push_back(shoe);

    ISuit* ISuit = factory->createSuit("4001",has1);
    auto* suit = dynamic_cast<Suit*> (ISuit);
    exists = suit;
    EXPECT_TRUE(exists);

    vector<Clothing*> has2;
    has2.push_back(suit);

    ISet* ISet = factory->createSet("5001",has2);
    auto* set = dynamic_cast<Set*> (ISet);
    exists = set;
    EXPECT_TRUE(exists);
}