#include "BuyerC.h"
#include <cppconn/prepared_statement.h>
using namespace std;
BuyerC::BuyerC(std::string login, std::string password, int rights, std::string name, std::string contactNumber)
    : Account(std::move(login), std::move(password), rights), name(std::move(name)), contactNumber(std::move(contactNumber)) {}
std::string BuyerC::getName() const {
    return name;
}
void BuyerC::setName(const std::string& name) {
    BuyerC::name = name;
}
std::string BuyerC::getContactNumber() const {
    return contactNumber;
}
void BuyerC::setContactNumber(const std::string& contactNumber) {
    BuyerC::contactNumber = contactNumber;
}
bool BuyerC::saveToDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("INSERT INTO buyer VALUES (?, ?, ?)");
        pstmt->setString(1, login);
        pstmt->setString(2, name);
        pstmt->setString(3, contactNumber);
        pstmt->execute();
        delete pstmt;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL error: " << e.what() << endl;
        return false;
    }
}
bool BuyerC::loadFromDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("SELECT * FROM buyer WHERE login = ?");
        pstmt->setString(1, login);
        sql::ResultSet* resultSet = pstmt->executeQuery();
        if (resultSet->next()) {
            name = resultSet->getString("name");
            contactNumber = resultSet->getString("contact_number");
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
bool BuyerC::updateInDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("UPDATE buyer SET name = ?, contact_number = ? WHERE login = ?");
        pstmt->setString(1, name);
        pstmt->setString(2, contactNumber);
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
