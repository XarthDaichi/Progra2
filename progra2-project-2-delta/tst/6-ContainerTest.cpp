//
// Created by Xarthy on 0020 June 20, 2022.
//

#include "gtest/gtest.h"
#include "../src/Container.h"
#include "../src/Set.h"
#include "../src/Suit.h"
#include "../src/Garment.h"

TEST(ContainerTestSuite, basicContainerTest) {
    Garment * g1 = new Garment("01", "Black", "Large", "Shirt:LongSleeve", true);
    Garment * g2 = new Garment("02", "Blue", "Medium", "Pant:Shorts", false);
    Garment * g3 = new Garment("03", "Brown", "Small", "Shoe:Boots", true);
    Container<Garment> garments;
    garments.push(g1);
    garments.push(g2);
    garments.push(g3);

    vector<Clothing *> clothingCastTemp = {g1, g2, g3};

    Suit* su1 = new Suit("04", "Mixt", clothingCastTemp);
    Suit* su2 = new Suit("05", "Mixt", clothingCastTemp);
    Suit* su3 = new Suit("06", "Mixt", clothingCastTemp);
    Suit* su4 = new Suit("07", "Mixt", clothingCastTemp);


    Container<Suit> suits;
    suits.push(su1);
    suits.push(su2);
    suits.push(su3);
    suits.push(su4);


    clothingCastTemp = {su1, su2, su3, su4};

    Set * se1 = new Set("08", clothingCastTemp);

    Container<Set> sets;
    sets.push(se1);

    EXPECT_EQ(garments.allObjects().size(), 3);
    EXPECT_EQ(suits.allObjects().size(), 4);
    EXPECT_EQ(sets.allObjects().size(), 1);

    EXPECT_TRUE(suits.allObjects()[0]->hasClothes()[0]->getCode() == g1->getCode());
    EXPECT_TRUE(sets.allObjects()[0]->hasClothes()[0]->getCode() == su1->getCode());
}

TEST(ContainerTestSuite, certainObjectsTest) {
    Garment * g1 = new Garment("01", "Black", "Large", "Shirt:LongSleeve", true);
    Garment * g2 = new Garment("02", "Blue", "Medium", "Pant:Shorts", false);
    Garment * g3 = new Garment("03", "Brown", "Small", "Shoe:Boots", true);
    Garment * g4 = new Garment("04", "Black", "Medium", "Shirt:TShirt", false);
    Container<Garment> garments;
    garments.push(g1);
    garments.push(g2);
    garments.push(g3);
    garments.push(g4);

    vector<Clothing *> clothingCastTemp = {g1, g2, g3};

    Suit* su1 = new Suit("05", "Mixt", clothingCastTemp);
    Suit* su2 = new Suit("06", "Mixt", clothingCastTemp);
    Suit* su3 = new Suit("07", "Mixt", clothingCastTemp);
    clothingCastTemp = {g4,g2,g3};
    Suit* su4 = new Suit("08", "Mixt", clothingCastTemp);

    Container<Suit> suits;
    suits.push(su1);
    suits.push(su2);
    suits.push(su3);
    suits.push(su4);


    clothingCastTemp = {su1, su2, su3, su4};

    Set * se1 = new Set("09", clothingCastTemp);

    clothingCastTemp = {su1, su2, su3};
    Set * se2 = new Set("10", clothingCastTemp);

    Container<Set> sets;
    sets.push(se1);
    sets.push(se2);

    EXPECT_EQ(garments.certainObjects("Black").size(), 2);
    EXPECT_EQ(suits.certainObjects(*g1).size(), 3);
    EXPECT_EQ(sets.certainObjects(*su4).size(), 1);
}