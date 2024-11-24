#ifndef TRANSACTION
#define TRANSACTION

#include "../../libs/libs.h"

namespace BankSystem 
{

    class Transaction 
    {
    private:
        string transactionID;
        string date;
        double amount;
        string fromAccount; 
        string toAccount;

        string generateTransactionID();

        string getCurrentDate();

    public:
        Transaction(const string& fromAcc, const string& toAcc, double amt);

        double getAmount() const;

        string getFromAccount() const;

        string getToAccount() const;

        string getTransactionID() const;

        string getDate() const;

        void saveTransaction(const string& filename) const;

        static vector<Transaction> loadTransactions(const string& filename);
    };
}

#endif

