//
// Created by ribre on 16/06/2022.
//

#ifndef MY_PROJECT_NAME_VIRTUALMANAGER_H
#define MY_PROJECT_NAME_VIRTUALMANAGER_H
#include "iostream"
#include <sstream>
#include <ostream>
#include <string>

using namespace  std;
class PricingManager {
public:
    PricingManager();

    virtual ~PricingManager();

    static double getShippingCost(int code);
    static double itemPrice(string type, bool characteristic, string size);
    static string getCity(int code);
    static string getCountry(int code);

};


#endif //MY_PROJECT_NAME_VIRTUALMANAGER_H
