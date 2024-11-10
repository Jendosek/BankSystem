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

    void Account::loadData(string filename)
    {
        ifstream inFile(filename);
        if (!inFile) {
            throw runtime_error("Unable to open file for loading.");
        }

        if (!getline(inFile, accountNumber)) {
            throw runtime_error("Error reading account number from file.");
        }

        if (!(inFile >> balance)) {
            throw runtime_error("Error reading balance from file.");
        }

        inFile.close();

        if (accountNumber.empty()) {
            throw runtime_error("Account number loaded from file is empty.");
        }
    }

    void Account::saveData(string filename)
    {
        ofstream outFile(filename);
        if (!outFile) {
            throw runtime_error("Unable to open file for saving.");
        }

        outFile << accountNumber << "\n" << balance << "\n";

        if (!outFile.good()) {
            throw runtime_error("Error occurred while writing to file.");
        }

        outFile.close();
    }
}