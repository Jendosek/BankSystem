#include "transaction.h"


namespace BankSystem {
    string Transaction::generateTransactionID() {
        static int counter = 0;
        return "TX" + to_string(++counter);
    }

    // Форматує поточну дату як рядок
    string Transaction::getCurrentDate() {
        time_t now = time(nullptr);
        tm localTime;
        localtime_s(&localTime, &now);

        // Формат дати як "YYYY-MM-DD HH:MM:SS"
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime);
        return string(buffer);
    }

    // Конструктор для створення транзакції
    Transaction::Transaction(const string& fromAcc, const string& toAcc, double amt)
        : fromAccount(fromAcc), toAccount(toAcc), amount(amt) {
        transactionID = generateTransactionID();
        date = getCurrentDate();
    }

    // Повертає суму транзакції
    double Transaction::getAmount() const {
        return amount;
    }

    // Повертає номер акаунту-джерела
    string Transaction::getFromAccount() const {
        return fromAccount;
    }

    // Повертає номер акаунту-отримувача
    string Transaction::getToAccount() const {
        return toAccount;
    }

    // Повертає ідентифікатор транзакції
    string Transaction::getTransactionID() const {
        return transactionID;
    }

    // Повертає дату транзакції
    string Transaction::getDate() const {
        return date;
    }

    // Зберігає транзакцію у файл
    void Transaction::saveTransaction(const string& filename) const {
        ofstream outFile(filename, ios::app);
        if (!outFile) {
            throw runtime_error("Cannot open file for writing.");
        }

        outFile << transactionID << ","
            << date << ","
            << fromAccount << ","
            << toAccount << ","
            << amount << endl;

        outFile.close();
    }

    // Завантажує транзакції з файлу
    vector<Transaction> Transaction::loadTransactions(const string& filename) {
        vector<Transaction> transactions;
        ifstream inFile(filename);
        if (!inFile) {
            throw runtime_error("Cannot open file for reading.");
        }

        string line;
        while (getline(inFile, line)) {
            size_t pos = 0;
            string token;
            string transactionID, date, fromAccount, toAccount, amountStr;
            double amount;

            // Отримуємо перше поле (transactionID)
            pos = line.find(',');
            if (pos == string::npos) continue; // Якщо немає роздільника, пропускаємо рядок
            transactionID = line.substr(0, pos);
            line.erase(0, pos + 1);

            // Отримуємо друге поле (date)
            pos = line.find(',');
            if (pos == string::npos) continue;
            date = line.substr(0, pos);
            line.erase(0, pos + 1);

            // Отримуємо третє поле (fromAccount)
            pos = line.find(',');
            if (pos == string::npos) continue;
            fromAccount = line.substr(0, pos);
            line.erase(0, pos + 1);

            // Отримуємо четверте поле (toAccount)
            pos = line.find(',');
            if (pos == string::npos) continue;
            toAccount = line.substr(0, pos);
            line.erase(0, pos + 1);

            // Отримуємо п'яте поле (amountStr)
            amountStr = line; // решта рядка — це amount
            try {
                amount = stod(amountStr); // Перетворюємо в число
            }
            catch (const invalid_argument& e) {
                cerr << "Invalid amount format in line: " << line << endl;
                continue; // Пропускаємо цей рядок, якщо сума некоректна
            }

            // Створюємо транзакцію і додаємо її до списку
            Transaction transaction(fromAccount, toAccount, amount);
            transaction.transactionID = transactionID;
            transaction.date = date;
            transactions.push_back(transaction);
        }

        inFile.close();
        return transactions;
    }
}