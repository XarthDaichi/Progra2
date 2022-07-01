//
// Created by Xarthy on 0020 March 20, 2022.
//

#ifndef CLASESABSTRACTASEINTERFACES_BANKACCOUNT_H
#define CLASESABSTRACTASEINTERFACES_BANKACCOUNT_H
#include <iostream>

class BankAccount {
private:
    int bankNumber;
public:
    BankAccount(int bankNumber);

    virtual ~BankAccount();

    int getBankNumber() const;

    void setBankNumber(int bankNumber);
};


#endif //CLASESABSTRACTASEINTERFACES_BANKACCOUNT_H
