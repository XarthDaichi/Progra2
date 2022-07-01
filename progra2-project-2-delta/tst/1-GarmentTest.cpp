//
// Created by Xarthy on 0020 June 20, 2022.
//

#include "gtest/gtest.h"
#include "../src/Garment.h"
using namespace std;

TEST(GarmentTestSutie, CreatingGarments) {
    auto* g1 = new Garment;
    g1->setCode("01");
    g1->setColor("Black");
    g1->setSize("Large");
    g1->setType("Shirt:LongSleeve");
    g1->setCharacteristic(true);

    auto* g2 = new Garment("02", "Blue", "Small", "Shirt:LongSleeve", false);

    EXPECT_STREQ(g1->getCode().c_str(), "01");
    EXPECT_STREQ(g2->getCode().c_str(), "02");
    EXPECT_TRUE(g1->getType() == g2->getType());
}
