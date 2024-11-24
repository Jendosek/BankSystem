#ifndef I_ACCOUNT
#define I_ACCOUNT

#include "../../libs/libs.h"
#include "../domain/account.h" 

class IAccountService {
public:
    virtual ~IAccountService() = default;

    virtual void createAccount(const string& accountNumber, double initialBalance) = 0;

    virtual void deleteAccount(const string& accountNumber) = 0;

    virtual void depositToAccount(const string& accountNumber, double amount) = 0;

    virtual void withdrawFromAccount(const string& accountNumber, double amount) = 0;

    virtual BankSystem::Account* findAccount(const string& accountNumber) = 0;

    virtual vector<BankSystem::Account> getAllAccounts() const = 0;
};

#endif 