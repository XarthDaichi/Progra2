//
// Created by Xarthy on 0020 June 20, 2022.
//
#include "gtest/gtest.h"
#include "../src/Garment.h"
#include "../src/Suit.h"

using namespace std;

TEST(SuitTestSuite, SuitTest) {
    Garment * g1 = new Garment("01", "Black", "Large", "Shirt:LongSleeve", true);
    Garment * g2 = new Garment("02", "Blue", "Medium", "Pant:Shorts", false);
    Garment * g3 = new Garment("03", "Brown", "Small", "Shoe:Boots", true);
    Garment * g4 = new Garment("04", "Black", "Medium", "Shirt:T-shirt", false);
    Garment * g5 = new Garment("05", "Blue", "Large", "Pant:Jeans", true);
    Garment * g6 = new Garment("06", "Black", "Large", "Shoe:Executive", false);

    vector<Clothing *> temp1 = {g1,g2,g3};

    Suit * s1 = new Suit("07", "Mixt", temp1);
    Suit * s2 = new Suit();
    s2->setCode("08");
    s2->setType("Mixt");
    s2->add(g4);
    s2->add(g5);
    s2->add(g6);

    stringstream s;

    s << *s1;

    EXPECT_STREQ(s.str().c_str(), " code: 07 price: 635 has:  code: 01 price: 375 color: Black size: Large "
                                  "type: Shirt:LongSleeve characteristic: 1 -  "
                                  "code: 02 price: 85 color: Blue size: Medium "
                                  "type: Pant:Shorts characteristic: 0 -  code: 03 price: 175 color: "
                                  "Brown size: Small type: Shoe:Boots characteristic: 1 - ");
    s.str("");
    s << *s2;
    EXPECT_STREQ(s.str().c_str(),  " code: 08 price: 700 has:  code: 04 price: 100 color: Black size: Medium type: Shirt:T-shirt characteristic: 0 -  code: 0"
                                   "5 price: 200 color: Blue size: Large type: Pant:Jeans characteristic: 1 -  code: 06 price: 400 color: Black size: Large ty"
                                   "pe: Shoe:Executive characteristic: 0 - ");
}

TEST(SuitTestSuite, SuitRemoveTest) {
    Garment * g1 = new Garment("01", "Black", "Large", "Shirt:LongSleeve", true);
    Garment * g2 = new Garment("02", "Blue", "Medium", "Pant:Shorts", false);
    Garment * g3 = new Garment("03", "Brown", "Small", "Shoe:Boots", true);
    Garment * g4 = new Garment("04", "Black", "Medium", "Shirt:TShirt", false);
    Garment * g5 = new Garment("05", "Blue", "Large", "Pant:Jeans", true);
    Garment * g6 = new Garment("06", "Black", "Large", "Shoe:Executive", false);

    vector<Clothing *> temp1 = {g1,g2,g3};

    Suit * s1 = new Suit("07", "Mixt", temp1);
    Suit * s2 = new Suit();
    s2->setCode("08");
    s2->setType("Mixt");
    s2->add(g4);
    s2->add(g5);
    s2->add(g6);

    EXPECT_TRUE(s1->hasClothes() != s2->hasClothes());

    s2->remove(g4);

    EXPECT_EQ(s2->hasClothes().size(), 2);
    s2->remove(g5);
    s2->remove(g6);

    s2->add(g1);
    s2->add(g2);
    s2->add(g3);

    EXPECT_EQ(s1->hasClothes(), s2->hasClothes());
}
