#include "project_service.h"

using namespace BankSystem;

int main()
{
    std::string accountNumber;
    double initialBalance;

    // Завантажуємо дані з файлу при запуску програми
    Account account("", 0.0); // Тимчасовий об'єкт для завантаження даних
    std::ifstream inFile("account_data.txt");

    if (inFile.is_open()) {
        account.loadData(inFile);
        inFile.close();
        std::cout << "Account loaded successfully.\n"
            << "Account Number: " << account.getAccountNumber()
            << "\nBalance: " << account.getBalance() << "\n\n";
    }
    else {
        std::cout << "No previous account data found. Please create a new account.\n";

        // Запитуємо у користувача дані для створення нового рахунку
        std::cout << "Enter account number: ";
        std::cin >> accountNumber;
        std::cout << "Enter initial balance: ";
        std::cin >> initialBalance;

        account = Account(accountNumber, initialBalance);
    }

    // Меню для користувача
    int choice;
    do {
        std::cout << "\n--- Bank Account Menu ---\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Show Balance\n";
        std::cout << "4. Exit and Save\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            double amount;
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;
            try {
                account.deposit(amount);
                std::cout << "Deposit successful. New balance: " << account.getBalance() << "\n";
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
            }
            break;
        }
        case 2: {
            double amount;
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amount;
            try {
                account.withdraw(amount);
                std::cout << "Withdrawal successful. New balance: " << account.getBalance() << "\n";
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
            }
            break;
        }
        case 3:
            std::cout << "Current balance: " << account.getBalance() << "\n";
            break;
        case 4:
            std::cout << "Exiting and saving data...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    // Збереження даних рахунку у файл при виході
    std::ofstream outFile("account_data.txt");
    if (outFile.is_open()) {
        account.saveData(outFile);
        outFile.close();
        std::cout << "Account data saved successfully.\n";
    }
    else {
        std::cerr << "Error: Unable to open file for saving.\n";
    }

	return 0;
}