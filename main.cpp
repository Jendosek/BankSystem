#include "project_service.h"

using namespace BankSystem;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    string userName, userID;

    cout << "Welcome to the Bank System" << endl;

    // Запитуємо у користувача ім'я та ID
    cout << "Enter your name: ";
    cin >> userName;

    cout << "Enter your user ID: ";
    cin >> userID;



    User user(userName, userID); // Створюємо користувача

    bool running = true;

    while (running) {
        cout << "\nChoose an action:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Remove Account" << endl;
        cout << "3. Show All Accounts" << endl;
        cout << "4. Deposit to Account" << endl;
        cout << "5. Withdraw from Account" << endl;
        cout << "6. Save User Data" << endl;
        cout << "7. Load User Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            // Додаємо новий акаунт
            string accountNumber;
            double initialBalance;

            cout << "Enter new account number: ";
            cin >> accountNumber;
            cout << "Enter initial balance: ";
            cin >> initialBalance;

            Account newAccount(accountNumber, initialBalance);
            user.addAccount(newAccount);

            cout << "Account created successfully." << endl;
            break;
        }
        case 2: {
            // Видаляємо акаунт
            string accountNumber;
            cout << "Enter account number to remove: ";
            cin >> accountNumber;

            user.removeAccount(accountNumber);
            cout << "Account removed (if it existed)." << endl;
            break;
        }
        case 3:
            // Показуємо всі акаунти користувача
            user.showAccounts();
            break;
        case 4: {
            // Внесення коштів на певний акаунт
            string accountNumber;
            double amount;

            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter amount to deposit: ";
            cin >> amount;

            Account* account = user.findAccount(accountNumber);
            if (account) {
                try {
                    account->deposit(amount);
                    cout << "Deposited $" << amount << " successfully." << endl;
                }
                catch (const std::exception& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }
            else {
                cout << "Account not found." << endl;
            }
            break;
        }
        case 5: {
            // Зняття коштів з певного акаунту
            string accountNumber;
            double amount;

            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            Account* account = user.findAccount(accountNumber);
            if (account) {
                try {
                    account->withdraw(amount);
                    cout << "Withdrew $" << amount << " successfully." << endl;
                }
                catch (const std::exception& e) {
                    cerr << "Error: " << e.what() << endl;
                }
            }
            else {
                cout << "Account not found." << endl;
            }
            break;
        }
        case 6: {
            // Зберігаємо дані користувача у файл
            string filename;
            cout << "Enter filename to save user data: ";
            cin >> filename;

            try {
                user.saveData(filename);
                cout << "User data saved to " << filename << endl;
            }
            catch (const std::exception& e) {
                cerr << "Error saving data: " << e.what() << endl;
            }
            break;
        }
        case 7: {
            // Завантажуємо дані користувача з файлу
            string filename;
            cout << "Enter filename to load user data: ";
            cin >> filename;

            try {
                user.loadData(filename);
                cout << "User data loaded successfully." << endl;
            }
            catch (const std::exception& e) {
                cerr << "Error loading data: " << e.what() << endl;
            }
            break;
        }
        case 8:
            // Вихід з програми
            running = false;
            cout << "Exiting the Bank System. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
    
}