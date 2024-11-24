#ifndef I_ACCOUNT
#define I_ACCOUNT

#include "../../libs/libs.h"
#include "../domain/account.h" // Include the Account header file

class IAccountService {
public:
    virtual ~IAccountService() = default;

    // Створення нового акаунту
    virtual void createAccount(const std::string& accountNumber, double initialBalance) = 0;

    // Видалення акаунту
    virtual void deleteAccount(const std::string& accountNumber) = 0;

    // Поповнення акаунту
    virtual void depositToAccount(const std::string& accountNumber, double amount) = 0;

    // Зняття з акаунту
    virtual void withdrawFromAccount(const std::string& accountNumber, double amount) = 0;

    // Пошук акаунту
    virtual BankSystem::Account* findAccount(const std::string& accountNumber) = 0;

    // Отримання всіх акаунтів
    virtual std::vector<BankSystem::Account> getAllAccounts() const = 0;
};

#endif // !I_ACCOUNT
