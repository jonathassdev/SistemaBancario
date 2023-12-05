//
// Criado por eddub em 14/11/2023.
//

#include "SavingsAccount.h"


// Construtor padrão
SavingsAccount::SavingsAccount()
        : Account(), ir(0.05) { // // Taxa de juros de 5% a.m

}

// Construtor com parâmetros
SavingsAccount::SavingsAccount(const int accountNumber)
        : Account(accountNumber), ir(0.05) {

}

double SavingsAccount::calcIR() const {
    return balance * ir;
}

void SavingsAccount::applyIR() {
    double interest = balance * ir;
    balance += interest;
}

// Métodos sobrescritos
bool SavingsAccount::deposit(const double amount) {

    if(amount <= 0) {
        cout << "ERRO: A quantia depositada deve ser um valor positivo." << endl;
        return false;
    }

    // Atualizar saldo
    balance += amount;

    cout << "A conta foi creditada com R$" << amount << endl;
    cout << "Saldo Atual: R$" << balance << endl;
    return true;
}

bool SavingsAccount::withdraw(const double amount) {

    // Deve ser um valor positivo
    if(amount <= 0) {
        cout << "ERRO: A quantia de saque deve ser um valor positivo." << endl;
        return false;
    }

    // Saldo suficiente
    if(amount <= balance) {

        balance -= amount;

        cout << "Saque de R$" << amount << " realizado." << endl;
        cout << "Saldo Atual: $" << balance << endl;
        return true;
    }

    cout << "Saldo insuficiente para sacar R$" << amount << endl;
    cout << "Saldo Atual: R$" << balance << endl;
    return false;
}