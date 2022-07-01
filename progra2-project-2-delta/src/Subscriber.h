//
// Created by ribre on 21/06/2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_SUBSCRIBER_H
#define PROGRA_PROJECT_2_DELTA_SUBSCRIBER_H
#include <ostream>
#include <iostream>
#include <sstream>
#include "IObserver.h"
#include "PricingManager.h"

using namespace std;
class Subscriber : public IObserver{
protected:
    string name;
    string id;
    double subPay;
    double sendCost;
    string city;
    string country;
    int countryCode;
    bool online;
public:
    Subscriber();

    Subscriber(const string &name, const string &id, double subPay, int countryCode, bool online);

    ~Subscriber() override;

    const string &getName() const;

    void setName(const string &name);

    const string &getId() const;

    void setId(const string &id);

    bool isOnline() const;

    void setOnline(bool online);

    virtual double getSubPay();

    int getCountryCode() const;

    void setCountryCode(int countryCode);

    double getSendCost() const;

    void setSendCost(double sendCost);

    const string &getCountry() const;

    void setCountry(const string &country);

    const string &getCity() const;

    void setCity(const string &city);

        virtual string toString();

    void update(Set * stock, Set* catalog) override;

    friend ostream &operator<<(ostream &os, const Subscriber &subscriber);


};


#endif //PROGRA_PROJECT_2_DELTA_SUBSCRIBER_H
