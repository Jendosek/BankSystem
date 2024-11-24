#ifndef TRANSACTION
#define TRANSACTION

#include "../../libs/libs.h"

namespace BankSystem {

    class Transaction {
    private:
        std::string transactionID;
        std::string date;         // Дата транзакції
        double amount;            // Сума транзакції
        std::string fromAccount;  // Номер акаунту-джерела
        std::string toAccount;    // Номер акаунту-отримувача (може бути пустим для депозиту/зняття)

        // Генерує унікальний ідентифікатор транзакції
        std::string generateTransactionID();

        // Форматує поточну дату як рядок
        std::string getCurrentDate();

    public:
        // Конструктор для створення транзакції
        Transaction(const std::string& fromAcc, const std::string& toAcc, double amt);

        // Повертає суму транзакції
        double getAmount() const;

        // Повертає номер акаунту-джерела
        std::string getFromAccount() const;

        // Повертає номер акаунту-отримувача
        std::string getToAccount() const;

        // Повертає ідентифікатор транзакції
        std::string getTransactionID() const;

        // Повертає дату транзакції
        std::string getDate() const;

        // Зберігає транзакцію у файл
        void saveTransaction(const std::string& filename) const;

        // Завантажує транзакції з файлу
        static std::vector<Transaction> loadTransactions(const std::string& filename);
    };
}

#endif // !TRANSACTION

