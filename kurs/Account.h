#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <cppconn/connection.h>
class Account {
protected:
    std::string login;
    std::string password;
    int rights;
public:
    Account(std::string login, std::string password, int rights);
    std::string getLogin() const;
    std::string getPassword() const;
    int getRights() const;
    void setLogin(const std::string& login);
    void setPassword(const std::string& password);
    void setRights(int rights);
    bool saveToDatabase(sql::Connection* connection);
    bool loadFromDatabase(sql::Connection* connection);
    bool updateInDatabase(sql::Connection* connection);
};
#endif // ACCOUNT_H
