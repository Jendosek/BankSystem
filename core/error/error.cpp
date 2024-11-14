#include "error.h"

namespace BankSystem {

    // Конструктор для ініціалізації повідомлення про помилку
    BankException::BankException(const std::string& msg) {
        message = msg;
    }

    // Метод для отримання повідомлення про помилку
    const char* BankException::what() const noexcept {
        return message.c_str();
    }
}