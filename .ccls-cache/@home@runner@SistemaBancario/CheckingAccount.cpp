//
// Created by eddub on 14/11/2023.
//

#include "CheckingAccount.h"


// Default constructor
CheckingAccount::CheckingAccount()
        : Account() {

}

// Parameter constructor
CheckingAccount::CheckingAccount(const int accountNUmber)
        : Account(accountNUmber) { // account number

}

// overridden methods
bool CheckingAccount::deposit(const double amount) {

    if(amount <= 0) {
        cout << "ERRO: O valor do depósito deve ser um valor positivo." << endl;
        return false;
    }

    // update balance
    balance += amount;

    cout << "Conta creditada em R$" << amount << endl;
    cout << "Saldo Atual: R$" << balance << endl;
    return true;
}

bool CheckingAccount::withdraw(const double amount) {

    // must be positive value
    if(amount <= 0) {
        cout << "ERRO: O valor do saque deve ser um valor positivo." << endl;
        return false;
    }

    // Sufficient valance
    if(amount <= balance) {

        balance -= amount;

        cout << "Saque de R$" << amount << " realizado." << endl;
        cout << "Current Balance: $" << balance << endl;
        return true;
    }

    cout << "Saldo insuficiente para sacar R$" << amount << endl;
    cout << "Saldo Atual: R$" << balance << endl;
    return false;
}