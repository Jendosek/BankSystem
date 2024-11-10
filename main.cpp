#include "project_service.h"

using namespace BankSystem;

int main()
{

    

    return 0;
    
}

// “≈—“ Õ¿ ¿ ¿”Õ“
/*string accountNumber;
    double initialBalance;

    cout << "Welcome to the Bank System" << endl;

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    Account account(accountNumber, initialBalance);

    bool running = true;
    while (running) {
        cout << "\nChoose an action:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Show Balance" << endl;
        cout << "4. Save Account Data" << endl;
        cout << "5. Load Account Data" << endl;
        cout << "6. Exit" << endl;
        cout << "Your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            try {
                account.deposit(amount);
                cout << "Deposited $" << amount << " successfully." << endl;
            }
            catch (const std::exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;
        }
        case 2: {
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            try {
                account.withdraw(amount);
                cout << "Withdrew $" << amount << " successfully." << endl;
            }
            catch (const std::exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
            break;
        }
        case 3:
            cout << "Current Balance: $" << account.getBalance() << endl;
            break;
        case 4: {
            string filename;
            cout << "Enter filename to save data: ";
            cin >> filename;
            try {
                account.saveData(filename);
                cout << "Account data saved to " << filename << endl;
            }
            catch (const std::exception& e) {
                cerr << "Error saving data: " << e.what() << endl;
            }
            break;
        }
        case 5: {
            string filename;
            cout << "Enter filename to load data: ";
            cin >> filename;
            try {
                account.loadData(filename);
                cout << "Account data loaded successfully." << endl;
                cout << "Account Number: " << account.getAccountNumber() << endl;
                cout << "Balance: $" << account.getBalance() << endl;
            }
            catch (const std::exception& e) {
                cerr << "Error loading data: " << e.what() << endl;
            }
            break;
        }
        case 6:
            running = false;
            cout << "Exiting the Bank System. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }*/