//
// Created by Xarthy on 0017 May 17, 2022.
//
#include "DigitalCopyVideogame.h"
#include "PhysicalCopyVideogame.h"
#include "DiscountedVideogame.h"
#include "Person.h"
#include "CostumePerson.h"


int main() {
    DigitalCopyVideogame dVideogame("Star Wars Jedi: Fallen Order Deluxe Edition", "Respawn Entertainment", 39.99, "Steam");
    PhysicalCopyVideogame pVideogame("Hollow Knight", "Team Cherry", 9.99, "Walmart");
    Person person("Diego", 18);


    cout << dVideogame << endl;
    cout << pVideogame << endl;
    cout << person << endl;

    DiscountedVideogame disVideogame1(dVideogame, 0.80);
    DiscountedVideogame disVideogame2(pVideogame, 0.20);
    CostumePerson cPerson(person, "Robin");


    cout << disVideogame1 << endl;
    cout << disVideogame2 << endl;
    cout << cPerson << endl;
    return 0;
}