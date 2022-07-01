//
// Created by ribre on 15/06/2022.
//

#ifndef MY_PROJECT_NAME_CLIENT_H
#define MY_PROJECT_NAME_CLIENT_H

#include "IObserver.h"
#include "PricingManager.h"
#include "Subscriber.h"
using namespace std;
class Client: public Subscriber {
private:
    string email;
public:
    Client();

    Client(const string &name, const string &id, int countryCode, bool online, const string &email);

    ~Client() override;

    const string &getEmail() const;

    void setEmail(const string &email);

    double getSubPay() override;

    friend ostream &operator<<(ostream &os, const Client &client);

    string toString() override;
};


#endif //MY_PROJECT_NAME_CLIENT_H
