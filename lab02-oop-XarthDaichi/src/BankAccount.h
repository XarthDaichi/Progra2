//
// Created by Xarthy on 0020 March 20, 2022.
//

#ifndef CLASESABSTRACTASEINTERFACES_BANKACCOUNT_H
#define CLASESABSTRACTASEINTERFACES_BANKACCOUNT_H
#include <iostream>
using namespace std;

class BankAccount {
private:
    int bankNumber;
public:
    BankAccount();

    BankAccount(int bankNumber);

    virtual ~BankAccount();

    int getBankNumber() const;

    void setBankNumber(int bankNumber);

    friend ostream &operator<<(ostream &os, const BankAccount &account);
};


#endif //CLASESABSTRACTASEINTERFACES_BANKACCOUNT_H
