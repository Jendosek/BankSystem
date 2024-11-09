#include "account.h"

namespace BankSystem 
{
    Account::Account(string accNum, double initialBalance)
    {
        accountNumber = accNum;
        balance = initialBalance;
    }

    Account::~Account() = default;

    void Account::deposit(double amount) 
    {
        if (amount < 0) throw invalid_argument("Amount must be positive.");
        balance += amount;
    }

    void Account::withdraw(double amount) 
    {
        if (amount > balance) throw runtime_error("Insufficient funds.");
        balance -= amount;
    }

    double Account::getBalance()
    {
        return balance;
    }

    string Account::getAccountNumber()
    {
        return accountNumber;
    }

    void Account::loadData(ifstream file)
    {
        file >> accountNumber >> balance;
    }

    void Account::saveData(ofstream file)
    {
        file << accountNumber << " " << balance << endl;
    }
}