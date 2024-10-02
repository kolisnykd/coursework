#include "SellerC.h"
#include <cppconn/prepared_statement.h>
using namespace std;
SellerC::SellerC(std::string login, std::string password, int rights, std::string contactNumber, std::string title,
    std::string name, std::string trackNumber, std::string workingDaysOfWeek, int additionalDaysOff)
    : Account(std::move(login), std::move(password), rights), contactNumber(std::move(contactNumber)),
    title(std::move(title)), name(std::move(name)), trackNumber(std::move(trackNumber)),
    workingDaysOfWeek(std::move(workingDaysOfWeek)), additionalDaysOff(additionalDaysOff) {}
std::string SellerC::getContactNumber() const {
    return contactNumber;
}
void SellerC::setContactNumber(const std::string& contactNumber) {
    SellerC::contactNumber = contactNumber;
}
std::string SellerC::getTitle() const {
    return title;
}
void SellerC::setTitle(const std::string& title) {
    SellerC::title = title;
}
std::string SellerC::getName() const {
    return name;
}
void SellerC::setName(const std::string& name) {
    SellerC::name = name;
}
std::string SellerC::getTrackNumber() const {
    return trackNumber;
}
void SellerC::setTrackNumber(const std::string& trackNumber) {
    SellerC::trackNumber = trackNumber;
}
std::string SellerC::getWorkingDaysOfWeek() const {
    return workingDaysOfWeek;
}
void SellerC::setWorkingDaysOfWeek(const std::string& workingDaysOfWeek) {
    SellerC::workingDaysOfWeek = workingDaysOfWeek;
}
int SellerC::getAdditionalDaysOff() const {
    return additionalDaysOff;
}
void SellerC::setAdditionalDaysOff(int additionalDaysOff) {
    SellerC::additionalDaysOff = additionalDaysOff;
}
bool SellerC::saveToDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("INSERT INTO employee VALUES (?, ?, ?, ?, ?)");
        pstmt->setString(1, login);
        pstmt->setString(2, contactNumber);
        pstmt->setString(3, title);
        pstmt->setString(4, name);
        pstmt->setString(5, trackNumber);
        pstmt->execute();
        delete pstmt;
        pstmt = connection->prepareStatement("INSERT INTO schedule VALUES (?, ?, ?)");
        pstmt->setString(1, login);
        pstmt->setString(2, workingDaysOfWeek);
        pstmt->setInt(3, additionalDaysOff);
        pstmt->execute();
        delete pstmt;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL error: " << e.what() << endl;
        return false;
    }
}
bool SellerC::loadFromDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("SELECT * FROM employee WHERE login = ?");
        pstmt->setString(1, login);
        sql::ResultSet* resultSet = pstmt->executeQuery();
        if (resultSet->next()) {
            contactNumber = resultSet->getString("contact_number");
            title = resultSet->getString("title");
            name = resultSet->getString("name");
            trackNumber = resultSet->getString("track_number");
            delete pstmt;
            delete resultSet;
            pstmt = connection->prepareStatement("SELECT * FROM schedule WHERE login = ?");
            pstmt->setString(1, login);
            resultSet = pstmt->executeQuery();
            if (resultSet->next()) {
                workingDaysOfWeek = resultSet->getString("working_days_of_the_week");
                additionalDaysOff = resultSet->getInt("additional_days_off");
            }
            delete pstmt;
            delete resultSet;
            return true;
        }
        else {
            delete pstmt;
            delete resultSet;
            return false;
        }
    }
    catch (sql::SQLException& e) {
        cerr << "SQL error: " << e.what() << endl;
        return false;
    }
}
bool SellerC::updateInDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("UPDATE employee SET contact_number = ?, title = ?, name = ?, track_number = ? WHERE login = ?");
        pstmt->setString(1, contactNumber);
        pstmt->setString(2, title);
        pstmt->setString(3, name);
        pstmt->setString(4, trackNumber);
        pstmt->setString(5, login);
        pstmt->execute();
        delete pstmt;
        pstmt = connection->prepareStatement("UPDATE schedule SET working_days_of_the_week = ?, additional_days_off = ? WHERE login = ?");
        pstmt->setString(1, workingDaysOfWeek);
        pstmt->setInt(2, additionalDaysOff);
        pstmt->setString(3, login);
        pstmt->execute();
        delete pstmt;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL error: " << e.what() << endl;
        return false;
    }
}
