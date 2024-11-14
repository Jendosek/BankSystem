#ifndef USER_H
#define USER_H

#include "../../libs/libs.h"
#include "account.h"

namespace BankSystem {

    class User {
    private:
        string name;
        string userID;
        vector<Account> accounts;

    public:

        User(string userName, string userID);

        // Методи для роботи з акаунтами
        void addAccount(Account account);
        void removeAccount(string accountNumber);
        Account* findAccount(string accountNumber);
        void showAccounts();

        // Методи для роботи з файлами
        void saveData(string filename);
        void loadData(string filename);
    };

} // namespace BankSystem

#endif 

