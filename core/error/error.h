#ifndef ERROR_H
#define ERROR_H

#include "../../libs/libs.h"

namespace BankSystem {

    class BankException : public exception {
    private:
        string message;

    public:
        explicit BankException(const string& msg);

        const char* what() const noexcept override;
    };
}

#endif 
