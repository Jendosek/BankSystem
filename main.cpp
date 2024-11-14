#include "project_service.h"

using namespace BankSystem;

int main()
{


    

    return 0;
    
}

// “≈—“ Õ¿ ¿ ¿”Õ“
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