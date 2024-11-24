#ifndef I_TRANSACTION
#define I_TRANSACTION

#include "../../libs/libs.h"
#include "../domain/transaction.h"

class ITransactionRepository {
public:
    virtual ~ITransactionRepository() = default;

    virtual void addTransaction(const BankSystem::Transaction& transaction) = 0;
    virtual vector<BankSystem::Transaction> getAllTransactions() const = 0;
    virtual void saveAllTransactions(const string& filename) = 0;
    virtual void loadAllTransactions(const string& filename) = 0;
};

#endif 

