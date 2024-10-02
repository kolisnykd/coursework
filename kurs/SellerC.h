#ifndef SELLERC_H
#define SELLERC_H
#include "account.h"
#include <cppconn/connection.h>
class SellerC : public Account {
private:
    std::string contactNumber;
    std::string title;
    std::string name;
    std::string trackNumber;
    std::string workingDaysOfWeek;
    int additionalDaysOff;
public:
    SellerC(std::string login, std::string password, int rights, std::string contactNumber, std::string title,
        std::string name, std::string trackNumber, std::string workingDaysOfWeek, int additionalDaysOff);
    std::string getContactNumber() const;
    void setContactNumber(const std::string& contactNumber);
    std::string getTitle() const;
    void setTitle(const std::string& title);
    std::string getName() const;
    void setName(const std::string& name);
    std::string getTrackNumber() const;
    void setTrackNumber(const std::string& trackNumber);
    std::string getWorkingDaysOfWeek() const;
    void setWorkingDaysOfWeek(const std::string& workingDaysOfWeek);
    int getAdditionalDaysOff() const;
    void setAdditionalDaysOff(int additionalDaysOff);
    bool saveToDatabase(sql::Connection* connection);
    bool loadFromDatabase(sql::Connection* connection);
    bool updateInDatabase(sql::Connection* connection);
};
#endif // SELLERC_H
