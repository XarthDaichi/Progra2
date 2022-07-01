//
// Created by Xarthy on 0020 March 20, 2022.
//

#include "BankAccount.h"

BankAccount::BankAccount(int bankNumber) : bankNumber(bankNumber) {}

BankAccount::~BankAccount() {

}

int BankAccount::getBankNumber() const {
    return bankNumber;
}

void BankAccount::setBankNumber(int bankNumber) {
    BankAccount::bankNumber = bankNumber;
}
