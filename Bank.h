//
// Created by eddub on 14/11/2023.
//

#ifndef UNTITLED_BANK_H
#define UNTITLED_BANK_H

#include <iostream>
#include <cstdlib>
#include <vector>

#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Bank {

public:
    // Add function
    void addAccount(Account *);
    Account * getAccount(const int);
    bool deposit(const int, const double);
    bool withdraw(const int, const double);
    bool transfer(const int, const int, const double);

    int getNextAccountNumber();

private:
    vector<Account *> accounts;
    static int nextAccountNumber;
};


#endif //UNTITLED_BANK_H
