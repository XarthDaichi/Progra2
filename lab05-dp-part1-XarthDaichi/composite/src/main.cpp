//
// Created by Xarthy on 0017 May 17, 2022.
//

#include "Dependant.h"
#include "Guardian.h"
#include "Household.h"

int main() {
    Dependant dp1("name1", 1, 1);
    Dependant dp2("name2", 2, 2);
    Dependant dp3("name3", 3, 3);
    Dependant dp4("name4", 4, 4);
    Dependant dp5("name5", 5, 5);

    Guardian gd1("name6", 6, 6);
    gd1.add(&dp1);
    gd1.add(&dp2);

    Guardian gd2("name7", 7, 7);
    gd2.add(&dp3);
    gd2.add(&dp4);
    gd2.add(&dp5);

    Household hh1;
    hh1.setId(1);
    hh1.setName("household1");
    hh1.add(&dp1);
    hh1.add(&dp2);
    hh1.add(&gd1);

    Household hh2;
    hh2.setId(2);
    hh2.setName("household2");
    hh2.add(&dp3);
    hh2.add(&dp4);
    hh2.add(&dp5);
    hh2.add(&gd2);

    cout << hh1 << endl << endl;
    cout << hh2 << endl << endl;

    return 0;
}