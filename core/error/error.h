#ifndef ERROR_H
#define ERROR_H

#include "../../libs/libs.h"

namespace BankSystem {

    // Клас для обробки помилок у банківській системі
    class BankException : public std::exception {
    private:
        std::string message;

    public:
        // Конструктор для ініціалізації повідомлення про помилку
        explicit BankException(const std::string& msg);

        // Метод для отримання повідомлення про помилку
        const char* what() const noexcept override;
    };
}


#endif 
