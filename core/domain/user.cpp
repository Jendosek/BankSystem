#include "user.h"


namespace BankSystem 
{
    User::User(string userName, string userID) 
    {
        this->name = userName;
        this->userID = userID;
    }

    void User::addAccount(Account account) 
    {
        accounts.push_back(account);
    }

    void User::removeAccount(string accountNumber) 
    {
        accounts.erase(remove_if(accounts.begin(), accounts.end(),
            [&accountNumber](Account acc) {
                return acc.getAccountNumber() == accountNumber; 
            }));
            accounts.end();
    }

    Account* User::findAccount(string accountNumber) 
    {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        return nullptr;
    }

    void User::showAccounts() {
        cout << "Користувач: " << name << " (ID: " << userID << ")" << endl;
        for (auto& account : accounts) {
            cout << "Номер рахунку: " << account.getAccountNumber() << ", Баланс: $" << account.getBalance() << endl;
        }
    }

    void User::saveData(string filename){
        ofstream outFile(filename);
        if (!outFile) {
            throw runtime_error("Неможливо відкрити файл для збереження.");
        }

        outFile << name << "\n" << userID << "\n" << accounts.size() << "\n";
        for (auto& account : accounts) {
            outFile << account.getAccountNumber() << "\n" << account.getBalance() << "\n";
        }

        if (!outFile.good()) {
            throw runtime_error("Під час запису даних користувача у файл сталася помилка.");
        }

        outFile.close();
    }

    void User::loadData(string filename) 
    {
        ifstream inFile(filename);
        if (!inFile) {
            throw runtime_error("Не вдається відкрити файл для завантаження.");
        }

        if (!getline(inFile, name) || !getline(inFile, userID)) {
            throw runtime_error("Помилка читання інформації користувача.");
        }

        size_t accountCount;
        if (!(inFile >> accountCount)) {
            throw runtime_error("Помилка читання кількості облікових записів.");
        }
        inFile.ignore();  

        accounts.clear();
        for (size_t i = 0; i < accountCount; ++i) 
        {
            string accNum;
            double balance;

            if (!getline(inFile, accNum) || !(inFile >> balance)) {
                throw runtime_error("Помилка читання даних облікового запису з файлу.");
            }
            inFile.ignore();  

            accounts.emplace_back(accNum, balance);
        }

        if (!inFile.good() && !inFile.eof()) {
            throw runtime_error("Під час читання даних користувача з файлу сталася помилка.");
        }

        inFile.close();
    }

}