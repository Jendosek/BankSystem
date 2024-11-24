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
        if (amount < 0) throw invalid_argument("Сума має бути позитивною.");
        balance += amount;
    }

    void Account::withdraw(double amount) 
    {
        if (amount > balance) throw runtime_error("Недостатньо коштів.");
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
            throw runtime_error("Не вдається відкрити файл для завантаження.");
        }

        if (!getline(inFile, accountNumber)) {
            throw runtime_error("Error reading account number from file.");
        }

        if (!(inFile >> balance)) {
            throw runtime_error("Помилка читання номера рахунку з файлу.");
        }

        inFile.close();

        if (accountNumber.empty()) {
            throw runtime_error("Номер рахунку, завантажений із файлу, порожній.");
        }
    }

    void Account::saveData(string filename)
    {
        ofstream outFile(filename);
        if (!outFile) {
            throw runtime_error("Неможливо відкрити файл для збереження.");
        }

        outFile << accountNumber << "\n" << balance << "\n";

        if (!outFile.good()) {
            throw runtime_error("Під час запису у файл сталася помилка.");
        }

        outFile.close();
    }
}