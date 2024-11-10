#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "../../libs/libs.h"

namespace BankSystem 
{
    class Account 
    {
    protected:
        string accountNumber;
        double balance;

    public:
        Account(string accNum, double initialBalance = INITIAL_DEPOSIT);
        virtual ~Account();

        virtual void deposit(double amount);
        virtual void withdraw(double amount);

        double getBalance();
        string getAccountNumber();

        virtual void loadData(string filename);
        virtual void saveData(string filename);
    };
}

#endif
