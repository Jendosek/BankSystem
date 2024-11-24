#include "transaction.h"


namespace BankSystem 
{
    string Transaction::generateTransactionID() 
    {
        static int counter = 0;
        return "TX" + to_string(++counter);
    }

    string Transaction::getCurrentDate() {
        time_t now = time(nullptr);
        tm localTime;
        localtime_s(&localTime, &now);

        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime);
        return string(buffer);
    }

    Transaction::Transaction(const string& fromAcc, const string& toAcc, double amt) : fromAccount(fromAcc), toAccount(toAcc), amount(amt) 
    {
        transactionID = generateTransactionID();
        date = getCurrentDate();
    }

    double Transaction::getAmount() const 
    {
        return amount;
    }

    string Transaction::getFromAccount() const 
    {
        return fromAccount;
    }

    string Transaction::getToAccount() const 
    {
        return toAccount;
    }

    string Transaction::getTransactionID() const 
    {
        return transactionID;
    }

    string Transaction::getDate() const 
    {
        return date;
    }

    void Transaction::saveTransaction(const string& filename) const {
        ofstream outFile(filename, ios::app);
        if (!outFile) {
            throw runtime_error("Неможливо відкрити файл для запису.");
        }

        outFile << transactionID << "," << date << "," << fromAccount << "," << toAccount << "," << amount << endl;
        outFile.close();
    }

    vector<Transaction> Transaction::loadTransactions(const string& filename) {
        vector<Transaction> transactions;
        ifstream inFile(filename);
        if (!inFile) {
            throw runtime_error("Не вдається відкрити файл для читання.");
        }

        string line;
        while (getline(inFile, line)) {
            size_t pos = 0;
            string token;
            string transactionID, date, fromAccount, toAccount, amountStr;
            double amount;

            pos = line.find(',');
            if (pos == string::npos) continue; 
            transactionID = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(',');
            if (pos == string::npos) continue;
            date = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(',');
            if (pos == string::npos) continue;
            fromAccount = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(',');
            if (pos == string::npos) continue;
            toAccount = line.substr(0, pos);
            line.erase(0, pos + 1);

            amountStr = line;
            try {
                amount = stod(amountStr);
            }
            catch (const invalid_argument& e) {
                cerr << "Недійсний формат суми в рядку: " << line << endl;
                continue;
            }

            Transaction transaction(fromAccount, toAccount, amount);
            transaction.transactionID = transactionID;
            transaction.date = date;
            transactions.push_back(transaction);
        }

        inFile.close();
        return transactions;
    }
}