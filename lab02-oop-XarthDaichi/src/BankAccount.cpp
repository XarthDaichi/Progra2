//
// Created by Xarthy on 0020 March 20, 2022.
//

#include "BankAccount.h"

BankAccount::BankAccount() {}

BankAccount::BankAccount(int bankNumber) : bankNumber(bankNumber) {}

BankAccount::~BankAccount() {

}

int BankAccount::getBankNumber() const {
    return bankNumber;
}

void BankAccount::setBankNumber(int bankNumber) {
    BankAccount::bankNumber = bankNumber;
}

ostream &operator<<(ostream &os, const BankAccount &account) {
    os << "bankNumber: " << account.bankNumber;
    return os;
}
