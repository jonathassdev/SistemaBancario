//
// Created by eddub on 14/11/2023.
//


#include <iostream>

#include <cstdlib>

#include "Account.h"
#include "Bank.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

// Protótipos de funções

//-----------------------------------------------------
// Nome: menu()
// Exibe o menu para o usuário e obtém a opção
//-----------------------------------------------------
int menu();

//-----------------------------------------------------
// Nome: createAccount()
// Cria um objeto e adiciona ao Banco
//-----------------------------------------------------
void createAccount(Bank & bank);

//-----------------------------------------------------
// Nome: deposit()
// Deposita uma quantia em uma conta
//-----------------------------------------------------
void deposit(Bank &);

//-----------------------------------------------------
// Nome: withdraw()
// Saca uma quantia de uma conta
//-----------------------------------------------------
void withdraw(Bank &);

//-----------------------------------------------------
// Nome: transfer()
// Transfere uma quantia entre contas
//-----------------------------------------------------
void transfer(Bank &);

//-----------------------------------------------------
// Nome: checkBalance()
// Verifica o saldo da conta
//-----------------------------------------------------
void checkBalance(Bank &);

//-----------------------------------------------------
// Nome: main()
// Ponto de entrada do programa.
//-----------------------------------------------------
int main() {

    // Declara um objeto da classe Bank
    Bank bank;

    // Opção do usuário
    int option;

    do
    {
        // Call menu
        option = menu();

        if(option == 1) { // Criar objeto
            createAccount(bank);
        } else if(option == 2) { // Verificar Saldo
            checkBalance(bank);
        } else if(option == 3) { // Depositar
            deposit(bank);
        } else if(option == 4) { // Sacar
            withdraw(bank);
        } else if(option == 5) { // Transferir
            transfer(bank);
        } else if(option == 0) { // Sair
            cout << "Obrigado por usar os nossos serviços!" << endl;
        }

        cout << endl;

    } while(option != 0);

    return 0;
}

int menu() {

    int option;

    do {
        cout << "\t\tBem-vindo ao Banco Alpha" << endl;
        cout << "\t\t1. Criar uma Conta" << endl;
        cout << "\t\t2. Verificar Saldo" << endl;
        cout << "\t\t3. Depositar" << endl;
        cout << "\t\t4. Saque" << endl;
        cout << "\t\t5. Transferir" << endl;
        cout << "\t\t0. Sair" << endl;
        cout << endl;
        cout << "Digite uma opção: ";
        cin >> option;

        if(option < 0 || option > 5) {
            cout << "ERRO: Entrada inválida - tente novamente!" << endl;
        }

    } while(option < 0 || option > 5);

    cout << endl;

    return option;
}

//-----------------------------------------------------
// Nome: create()
// Cria um objeto e adiciona ao Banco
//-----------------------------------------------------
void createAccount(Bank & bank) {

    Account * account;
    // Account * account = nullptr;
    int choice = 0;

    do {
        // Pergunta pelo tipo
        cout << "Selecione o Tipo de Conta" << endl;
        cout << "1. Conta Corrente" << endl;
        cout << "2. Conta Poupança" << endl;
        cout << "3. Voltar para o Menu Principal" << endl;
        cout << "Digite uma escolha: ";
        cin >> choice;

        if(choice < 1 || choice > 3) {
            cout << "ERRO: Escolha inválida - tente novamente!" << endl;
        }

    } while(choice < 1 || choice > 3);

    cout << endl;

    if(choice == 1 || choice == 2) {

        int accountNumber = bank.getNextAccountNumber();

        if(choice == 1) {
            account = new CheckingAccount(accountNumber);
            cout << "Conta corrente criada com o número da conta: " << accountNumber << endl;
        } else {
            account = new SavingsAccount(accountNumber);
            cout << "Conta poupança criada com o número da conta: " << accountNumber << endl;
        }

        bank.addAccount(account);
    }
}

//-----------------------------------------------------
// Nome: deposit()
// Deposita uma quantia em uma conta
//-----------------------------------------------------
void deposit(Bank & bank) {

    int accountNumber;
    double amount;

    // Obtem o número da conta
    cout << "Por favor, digite o número da conta: ";
    cin >> accountNumber;

    // Obtem a quantia a ser depositada
    cout << "Digite a quantia a ser depositada: ";
    cin >> amount;

    // Chama a função do banco
    if(bank.deposit(accountNumber, amount)) {
        cout << "Transação realizada com sucesso!" << endl;
    } else {
        cout << "Transação falhou!" << endl;
    }
}

//-----------------------------------------------------
// Nome: withdraw()
// Retira uma quantia de uma conta
//-----------------------------------------------------
void withdraw(Bank & bank) {
    int accountNumber;
    double amount;

    // Obtem o número da conta
    cout << "Por favor, digite o número da conta: ";
    cin >> accountNumber;

    // Obtem a quantia
    cout << "Digite a quantia a ser retirada: ";
    cin >> amount;

    // Chama a função do banco
    if(bank.withdraw(accountNumber, amount)) {
        cout << "Transação realizada com sucesso!" << endl;
    } else {
        cout << "Transação falhou!" << endl;
    }
}

//-----------------------------------------------------
// Nome: transfer()
// Transfere uma quantia entre contas
//-----------------------------------------------------
void transfer(Bank & bank) {
    int accountNumberFrom;
    int accountNumberTo;
    double amount;

    // Obtem o número da conta de origem
    cout << "Digite o número da conta de origem: ";
    cin >> accountNumberFrom;

    cout << "Digite o número da conta para transferência: ";
    cin >> accountNumberTo;

    // Obtem a quantia
    cout << "Digite a quantia da transferência: ";
    cin >> amount;

    // Chama a função do banco
    if(bank.transfer(accountNumberFrom, accountNumberTo, amount)) {
        cout << "Transação realizada com sucesso!" << endl;
    } else {
        cout << "Transação falhou!" << endl;
    }
}

//-----------------------------------------------------
// Nome: checkBalance()
// Verifica o saldo da conta
//-----------------------------------------------------
void checkBalance(Bank & bank) {
    int accountNumber;

    // Obtem o número da conta
    cout << "Digite o número da conta: ";
    cin >> accountNumber;

    Account * account = bank.getAccount(accountNumber);

    if(account != nullptr) {
        cout << "O saldo da sua conta é: R$" << account->getBalance() << endl;
    } else {
        cout << "Não existe tal conta com o número da conta: " << accountNumber << endl;
    }


}