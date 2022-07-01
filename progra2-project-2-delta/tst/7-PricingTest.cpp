//
// Created by Xarthy on 0020 June 20, 2022.
//
#include "gtest/gtest.h"
#include "../src/Garment.h"
#include "../src/Set.h"

TEST(PricingTestSuite, TestingGarmentPricing) {
    auto *g1 = new Garment("02", "Black", "Large", "Shirt:LongSleeve", true);
    auto *g2 = new Garment("01", "Blue", "Small", "Shirt:LongSleeve", false);
//Changes in size and characteristics make it cheaper even tho it is the same "type"
    auto *g3 = new Garment("03", "Red", "Medium", "Pant:DressUp", false);
    auto *g4 = new Garment("04", "White", "Small", "Shoe:Executive", true);
//Pricing is working fine with every garment
    EXPECT_EQ(g1->getPrice(),375);
    EXPECT_EQ(g2->getPrice(),150);
    EXPECT_EQ(g3->getPrice(),250);
    EXPECT_EQ(g4->getPrice(),325);
}
TEST(PricingTestSuite, TestingSuitPricing) {
    auto *g1 = new Garment("01", "White", "Child", "Shirt:LongSleeve", false);
    auto *g2 = new Garment("03", "Blue", "Child", "Pant:Jeans", false);
    auto *g3 = new Garment("04", "Black", "Child", "Shoe:Boots", false);
    vector<Clothing *> kidSuit = {g1,g2,g3};
    Suit * s1 = new Suit("11", "Children", kidSuit);

    auto *g4 = new Garment("05", "Black", "Large", "Shirt:WithSquares", true);
    auto *g5 = new Garment("06", "Black", "Large", "Pant:DressUp", true);
    auto *g6 = new Garment("07", "Black", "Large", "Shoe:Executive", true);
    vector<Clothing *> executiveSuit = {g4,g5,g6};
    Suit * s2 = new Suit("12", "ExecutiveMixt", executiveSuit);

    EXPECT_EQ(s1->calculatePrice(),225);
    //Second Suit is way more expensive since its componets are more expensive
    EXPECT_EQ(s2->calculatePrice(),1250);
}
TEST(PricingTestSuite, TestingSetPricing) {

    auto *g1 = new Garment("01", "White", "Child", "Shirt:LongSleeve", false);
    auto *g2 = new Garment("03", "Blue", "Child", "Pant:Jeans", false);
    auto *g3 = new Garment("04", "Black", "Child", "Shoe:Boots", false);
    vector<Clothing *> kidSuit = {g1,g2,g3};
    Suit * s1 = new Suit("11", "Children", kidSuit);

    auto *g4 = new Garment("05", "Black", "Large", "Shirt:WithSquares", true);
    auto *g5 = new Garment("06", "Black", "Large", "Pant:DressUp", true);
    auto *g6 = new Garment("07", "Black", "Large", "Shoe:Executive", true);
    vector<Clothing *> executiveSuit = {g4,g5,g6};
    Suit * s2 = new Suit("12", "ExecutiveMixt", executiveSuit);

    auto *g7 = new Garment("05", "Black", "Medium", "Shirt:WithSquares", true);
    auto *g8 = new Garment("06", "Red", "Large", "Pant:Jeans", true);
    auto *g9 = new Garment("07", "Blue", "Medium", "Shoe:Tennis", true);
    vector<Clothing *> personalizedSuit = {g7,g8,g9};
    Suit * s3 = new Suit("13", "PersonalizedSuit", personalizedSuit);

    vector<Clothing *> firstSet = {s1,s2,s3};
    Set *  set1 = new Set("21",firstSet);
//Really expensive because there is 3 sets
    EXPECT_EQ(set1->calculatePrice(),2225);
}