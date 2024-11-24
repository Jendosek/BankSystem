#ifndef I_USER
#define I_USER

#include "../../libs/libs.h"
#include "../domain/user.h"

class IUserService {
public:
    virtual ~IUserService() = default;

    virtual void registerUser(BankSystem::User user) = 0;
    virtual void removeUser(string userID) = 0;
    virtual BankSystem::User* findUser(string userID) = 0;
    virtual vector<BankSystem::User> getAllUsers() = 0;
    virtual void saveAllUsers(string filename) = 0;
    virtual void loadAllUsers(string filename) = 0;
};

#endif 

