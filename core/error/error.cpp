#include "error.h"

namespace BankSystem {

    BankException::BankException(const string& msg) {
        message = msg;
    }

    const char* BankException::what() const noexcept {
        return message.c_str();
    }
}