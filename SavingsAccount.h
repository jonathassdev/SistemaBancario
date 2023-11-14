//
// Created by eddub on 14/11/2023.
//

#ifndef UNTITLED_SAVINGSACCOUNT_H
#define UNTITLED_SAVINGSACCOUNT_H

#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

#include "Account.h"

class SavingsAccount : public Account {

public:

    // default constructor
    SavingsAccount();

    // Parameter constructor
    SavingsAccount(const int);

    // overridden methods
    virtual bool deposit(const double);
    virtual bool withdraw(const double);

    double calcIR() const;
    void applyIR();

private:
    double ir;

};


#endif //UNTITLED_SAVINGSACCOUNT_H
