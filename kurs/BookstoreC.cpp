#include "BookstoreC.h"
#include <cppconn/prepared_statement.h>
using namespace std;
std::string BookstoreC::getContactNumber() const {
    return contactNumber;
}
void BookstoreC::setContactNumber(const std::string& contactNumber) {
    BookstoreC::contactNumber = contactNumber;
}
std::string BookstoreC::getName() const {
    return name;
}
void BookstoreC::setName(const std::string& name) {
    BookstoreC::name = name;
}
std::string BookstoreC::getAddress() const {
    return address;
}
void BookstoreC::setAddress(const std::string& address) {
    BookstoreC::address = address;
}
std::string BookstoreC::getWorkSchedule() const {
    return workSchedule;
}
void BookstoreC::setWorkSchedule(const std::string& workSchedule) {
    BookstoreC::workSchedule = workSchedule;
}
bool BookstoreC::saveToDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("INSERT INTO bookstore VALUES (?, ?, ?, ?)");
        pstmt->setString(1, contactNumber);
        pstmt->setString(2, name);
        pstmt->setString(3, address);
        pstmt->setString(4, workSchedule);
        pstmt->execute();
        delete pstmt;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL error: " << e.what() << endl;
        return false;
    }
}
bool BookstoreC::loadFromDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("SELECT * FROM bookstore WHERE contact_number = ?");
        pstmt->setString(1, contactNumber);
        sql::ResultSet* resultSet = pstmt->executeQuery();
        if (resultSet->next()) {
            name = resultSet->getString("name");
            address = resultSet->getString("address");
            workSchedule = resultSet->getString("work_schedule");
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
bool BookstoreC::updateInDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("UPDATE bookstore SET name = ?, address = ?, work_schedule = ? WHERE contact_number = ?");
        pstmt->setString(1, name);
        pstmt->setString(2, address);
        pstmt->setString(3, workSchedule);
        pstmt->setString(4, contactNumber);
        pstmt->execute();
        delete pstmt;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL error: " << e.what() << endl;
        return false;
    }
}
