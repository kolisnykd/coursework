#ifndef BUYERC_H
#define BUYERC_H
#include "account.h"
#include <cppconn/connection.h>
class BuyerC : public Account {
private:
    std::string name;
    std::string contactNumber;
public:
    BuyerC(std::string login, std::string password, int rights, std::string name, std::string contactNumber);
    std::string getName() const;
    void setName(const std::string& name);
    std::string getContactNumber() const;
    void setContactNumber(const std::string& contactNumber);
    bool saveToDatabase(sql::Connection* connection);
    bool loadFromDatabase(sql::Connection* connection);
    bool updateInDatabase(sql::Connection* connection);
};
#endif // BUYERC_H
