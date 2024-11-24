#ifndef I_USER
#define I_USER

#include "../../libs/libs.h"
#include "../domain/user.h"

class IUserService {
public:
    virtual ~IUserService() = default;

    virtual void registerUser(BankSystem::User user) = 0;
    virtual void removeUser(std::string userID) = 0;
    virtual BankSystem::User* findUser(std::string userID) = 0;
    virtual std::vector<BankSystem::User> getAllUsers() = 0; // This should now work
    virtual void saveAllUsers(std::string filename) = 0;
    virtual void loadAllUsers(std::string filename) = 0;
};

#endif // !I_USER

