//
// Created by ribre on 21/06/2022.
//

#ifndef PROGRA_PROJECT_2_DELTA_COMPANY_H
#define PROGRA_PROJECT_2_DELTA_COMPANY_H

#include <ostream>
#include "IObserver.h"
#include "PricingManager.h"
#include "Subscriber.h"
using namespace std;
class Company: public Subscriber {
private:
    bool startup;
public:
    explicit Company(bool startup);

    Company(const string &name, const string &id, int countryCode, bool online, bool startup);

    ~Company() override;

    bool isStartup() const;

    void setStartup(bool startup);

    double getSubPay() override;

    friend ostream &operator<<(ostream &os, const Company &company);

    string toString() override;
};


#endif //PROGRA_PROJECT_2_DELTA_COMPANY_H
