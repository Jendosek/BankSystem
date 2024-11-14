#include "user.h"


namespace BankSystem {

    // Конструктор
    User::User(string userName, string userID) {
        this->name = userName;
        this->userID = userID;
    }

    // Додає акаунт до користувача
    void User::addAccount(Account account) {
        accounts.push_back(account);
    }

    // Видаляє акаунт за номером акаунта
    void User::removeAccount(string accountNumber) {
        accounts.erase(std::remove_if(accounts.begin(), accounts.end(),
            [&accountNumber](Account acc) {
                return acc.getAccountNumber() == accountNumber;
            }));
            accounts.end();
    }

    // Знаходить акаунт за номером акаунта
    Account* User::findAccount(string accountNumber) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        return nullptr;
    }

    // Відображає інформацію про всі акаунти користувача
    void User::showAccounts() {
        std::cout << "User: " << name << " (ID: " << userID << ")" << std::endl;
        for (auto& account : accounts) {
            std::cout << "Account Number: " << account.getAccountNumber()
                << ", Balance: $" << account.getBalance() << std::endl;
        }
    }

    // Зберігає дані користувача у файл
    void User::saveData(string filename){
        std::ofstream outFile(filename);
        if (!outFile) {
            throw std::runtime_error("Unable to open file for saving.");
        }

        // Записуємо основні дані користувача
        outFile << name << "\n" << userID << "\n" << accounts.size() << "\n";
        for (auto& account : accounts) {
            outFile << account.getAccountNumber() << "\n" << account.getBalance() << "\n";
        }

        if (!outFile.good()) {
            throw std::runtime_error("Error occurred while writing user data to file.");
        }

        outFile.close();
    }

    // Завантажує дані користувача з файлу
    void User::loadData(string filename) 
    {
        std::ifstream inFile(filename);
        if (!inFile) {
            throw std::runtime_error("Unable to open file for loading.");
        }

        // Читаємо основні дані користувача
        if (!std::getline(inFile, name) || !std::getline(inFile, userID)) {
            throw std::runtime_error("Error reading user information.");
        }

        size_t accountCount;
        if (!(inFile >> accountCount)) {
            throw std::runtime_error("Error reading the number of accounts.");
        }
        inFile.ignore();  // Пропускаємо залишковий символ нової строки

        accounts.clear();
        for (size_t i = 0; i < accountCount; ++i) {
            std::string accNum;
            double balance;

            if (!std::getline(inFile, accNum) || !(inFile >> balance)) {
                throw std::runtime_error("Error reading account data from file.");
            }
            inFile.ignore();  // Пропускаємо залишковий символ нової строки

            accounts.emplace_back(accNum, balance);
        }

        if (!inFile.good() && !inFile.eof()) {
            throw std::runtime_error("Error occurred while reading user data from file.");
        }

        inFile.close();
    }

} // namespace BankSystem
