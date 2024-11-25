#include "project_service.h"

using namespace BankSystem;

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    string userName, userID;
    cout << "Ласкаво просимо до банківської системи!" << endl;
    cout << "Введіть ваше ім'я: ";
    cin >> userName;
    cout << "Введіть ваш ID користувача: ";
    cin >> userID;

    User user(userName, userID);
    vector<Transaction> transactions;

    bool running = true;

    while (running) {
        clearConsole();
        cout << "---------------------------" << endl;
        cout << "       БАНКІВСЬКА СИСТЕМА       " << endl;
        cout << "---------------------------" << endl;
        cout << "1. Додати акаунт" << endl;
        cout << "2. Видалити акаунт" << endl;
        cout << "3. Показати всі акаунти" << endl;
        cout << "4. Поповнити акаунт" << endl;
        cout << "5. Зняти кошти з акаунта" << endl;
        cout << "6. Переглянути баланс акаунта" << endl;
        cout << "7. Виконати транзакцію" << endl;
        cout << "8. Показати історію транзакцій" << endl;
        cout << "9. Зберегти історію транзакцій" << endl;
        cout << "10. Завантажити історію транзакцій" << endl;
        cout << "11. Вийти" << endl;
        cout << "---------------------------" << endl;
        cout << "Оберіть дію: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            clearConsole();
            cout << "Додавання нового акаунта\n";
            string accountNumber;
            double initialBalance;
            cout << "Введіть номер акаунта: ";
            cin >> accountNumber;
            cout << "Введіть початковий баланс: ";
            cin >> initialBalance;

            Account newAccount(accountNumber, initialBalance);
            user.addAccount(newAccount);
            cout << "Акаунт успішно додано.\n";
            break;
        }
        case 2: {
            clearConsole();
            cout << "Видалення акаунта\n";
            string accountNumber;
            cout << "Введіть номер акаунта для видалення: ";
            cin >> accountNumber;

            user.removeAccount(accountNumber);
            cout << "Акаунт видалено (якщо він існував).\n";
            break;
        }
        case 3: {
            clearConsole();
            cout << "Список усіх акаунтів\n";
            user.showAccounts();
            break;
        }
        case 4: {
            clearConsole();
            cout << "Поповнення акаунта\n";
            string accountNumber;
            double amount;
            cout << "Введіть номер акаунта: ";
            cin >> accountNumber;
            cout << "Введіть суму для поповнення: ";
            cin >> amount;

            Account* account = user.findAccount(accountNumber);
            if (account) {
                account->deposit(amount);
                cout << "Поповнення успішно виконано.\n";
            }
            else {
                cout << "Акаунт не знайдено.\n";
            }
            break;
        }
        case 5: {
            clearConsole();
            cout << "Зняття коштів з акаунта\n";
            string accountNumber;
            double amount;
            cout << "Введіть номер акаунта: ";
            cin >> accountNumber;
            cout << "Введіть суму для зняття: ";
            cin >> amount;

            Account* account = user.findAccount(accountNumber);
            if (account) {
                try {
                    account->withdraw(amount);
                    cout << "Зняття коштів виконано успішно.\n";
                }
                catch (const exception& e) {
                    cout << "Помилка: " << e.what() << endl;
                }
            }
            else {
                cout << "Акаунт не знайдено.\n";
            }
            break;
        }
        case 6: {
            clearConsole();
            cout << "Перегляд балансу акаунта\n";
            string accountNumber;
            cout << "Введіть номер акаунта: ";
            cin >> accountNumber;

            Account* account = user.findAccount(accountNumber);
            if (account) {
                cout << "Баланс акаунта " << accountNumber << ": " << account->getBalance() << endl;
            }
            else {
                cout << "Акаунт не знайдено.\n";
            }
            break;
        }
        case 7: {
            clearConsole();
            cout << "Виконання транзакції між акаунтами\n";
            string fromAccountNumber, toAccountNumber;
            double amount;
            cout << "Введіть номер акаунта, з якого буде знято кошти: ";
            cin >> fromAccountNumber;
            cout << "Введіть номер акаунта, на який буде зараховано кошти: ";
            cin >> toAccountNumber;
            cout << "Введіть суму транзакції: ";
            cin >> amount;

            Account* fromAccount = user.findAccount(fromAccountNumber);
            Account* toAccount = user.findAccount(toAccountNumber);

            if (fromAccount && toAccount) {
                try {
                    fromAccount->withdraw(amount);
                    toAccount->deposit(amount);
                    Transaction transaction(fromAccountNumber, toAccountNumber, amount);
                    transactions.push_back(transaction);
                    cout << "Транзакція успішно виконана.\n";
                }
                catch (const exception& e) {
                    cout << "Помилка під час транзакції: " << e.what() << endl;
                }
            }
            else {
                cout << "Один із акаунтів не знайдено.\n";
            }
            break;
        }
        case 8: {
            clearConsole();
            cout << "Історія транзакцій\n";
            for (const auto& transaction : transactions) {
                transaction.display();
            }
            break;
        }
        case 9: {
            clearConsole();
            cout << "Збереження історії транзакцій\n";
            string filename;
            cout << "Введіть ім'я файлу для збереження історії: ";
            cin >> filename;

            Transaction::saveTransactions(transactions, filename);
            cout << "Історія транзакцій збережена в " << filename << ".\n";
            break;
        }
        case 10: {
            clearConsole();
            cout << "Завантаження історії транзакцій\n";
            string filename;
            cout << "Введіть ім'я файлу для завантаження історії: ";
            cin >> filename;

            transactions = Transaction::loadTransactions(filename);
            cout << "Історія транзакцій успішно завантажена.\n";
            break;
        }
        case 11: {
            clearConsole();
            cout << "Вихід із системи. До побачення!\n";
            running = false;
            break;
        }
        default: {
            clearConsole();
            cout << "Неправильний вибір. Спробуйте ще раз.\n";
            break;
        }
        }
        if (running) {
            cout << "\nНатисніть Enter для продовження...";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
    
}