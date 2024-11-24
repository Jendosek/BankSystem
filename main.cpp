#include "project_service.h"

using namespace BankSystem;

int main()
{

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

// ТЕСТ НА АКАУНТ
    //User user;

    //cout << "Welcome to the Bank System" << endl;

    //bool running = true;
    //while (running) {
    //    cout << "\nMenu:" << endl;
    //    cout << "1. Register a new user" << endl;
    //    cout << "2. Add a new account" << endl;
    //    cout << "3. Show all accounts" << endl;
    //    cout << "4. Save user data to file" << endl;
    //    cout << "5. Load user data from file" << endl;
    //    cout << "6. Find an account by number" << endl;
    //    cout << "7. Exit" << endl;
    //    cout << "Choose an option: ";

    //    int choice;
    //    cin >> choice;

    //    try {
    //        switch (choice) {
    //        case 1: {
    //            string userName, userID;
    //            cout << "Enter your name: ";
    //            cin >> userName;
    //            cout << "Enter your user ID: ";
    //            cin >> userID;
    //            user = User(userName, userID);
    //            cout << "User registered successfully." << endl;
    //            break;
    //        }
    //        case 2: {
    //            string accountNumber;
    //            double initialBalance;

    //            cout << "Enter account number: ";
    //            cin >> accountNumber;
    //            cout << "Enter initial balance: ";
    //            cin >> initialBalance;

    //            Account newAccount(accountNumber, initialBalance);
    //            user.addAccount(newAccount);

    //            cout << "Account created successfully." << endl;
    //            break;
    //        }
    //        case 3: {
    //            user.showAccounts();
    //            break;
    //        }
    //        case 4: {
    //            string filename;
    //            cout << "Enter filename to save user data: ";
    //            cin >> filename;
    //            user.saveData(filename);
    //            cout << "User data saved to " << filename << " successfully." << endl;
    //            break;
    //        }
    //        case 5: {
    //            string filename;
    //            cout << "Enter filename to load user data: ";
    //            cin >> filename;
    //            user.loadData(filename);
    //            cout << "User data loaded from " << filename << " successfully." << endl;
    //            break;
    //        }
    //        case 6: {
    //            string accountNumber;
    //            cout << "Enter account number to search: ";
    //            cin >> accountNumber;

    //            Account* account = user.findAccount(accountNumber);
    //            if (!account) {
    //                throw BankException("Account not found!");
    //            }

    //            cout << "Account found! Balance: $" << account->getBalance() << endl;
    //            break;
    //        }
    //        case 7: {
    //            cout << "Exiting the program. Goodbye!" << endl;
    //            running = false;
    //            break;
    //        }
    //        default: {
    //            throw BankException("Invalid menu choice!");
    //        }
    //        }
    //    }
    //    catch (const BankException& e) {
    //        cerr << "Bank error: " << e.what() << endl;
    //    }
    //    catch (const std::exception& e) {
    //        cerr << "Standard error: " << e.what() << endl;
    //    }
    //}