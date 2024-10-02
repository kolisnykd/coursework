#include "VisitC.h"
#include <cppconn/prepared_statement.h>
using namespace std;
std::string VisitC::getLogin() const {
    return login;
}
void VisitC::setLogin(const std::string& login) {
    VisitC::login = login;
}
std::string VisitC::getContactNumber() const {
    return contactNumber;
}
void VisitC::setContactNumber(const std::string& contactNumber) {
    VisitC::contactNumber = contactNumber;
}
std::string VisitC::getNote() const {
    return note;
}
void VisitC::setNote(const std::string& note) {
    VisitC::note = note;
}
std::string VisitC::getVisitDate() const {
    return visitDate;
}
void VisitC::setVisitDate(const std::string& visitDate) {
    VisitC::visitDate = visitDate;
}
std::string VisitC::getTimeVisit() const {
    return timeVisit;
}
void VisitC::setTimeVisit(const std::string& timeVisit) {
    VisitC::timeVisit = timeVisit;
}
bool VisitC::saveToDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("INSERT INTO visit (login, contact_number, visit_date, time_visit, note) VALUES (?, ?, ?, ?, ?)");
        pstmt->setString(1, login);
        pstmt->setString(2, contactNumber);
        pstmt->setString(3, visitDate);
        pstmt->setString(4, timeVisit);
        pstmt->setString(5, note);
        pstmt->execute();
        delete pstmt;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL error: " << e.what() << endl;
        return false;
    }
}
bool VisitC::loadFromDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("SELECT * FROM visit WHERE login = ? AND contact_number = ? AND visit_date = ? AND time_visit = ?");
        pstmt->setString(1, login);
        pstmt->setString(2, contactNumber);
        pstmt->setString(3, visitDate);
        pstmt->setString(4, timeVisit);
        sql::ResultSet* resultSet = pstmt->executeQuery();
        if (resultSet->next()) {
            login = resultSet->getString("login");
            contactNumber = resultSet->getString("contact_number");
            visitDate = resultSet->getString("visit_date");
            timeVisit = resultSet->getString("time_visit");
            note = resultSet->getString("note");
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
bool VisitC::updateInDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("UPDATE visit SET login = ?, contact_number = ?, visit_date = ?, time_visit = ?, note = ? WHERE login = ? AND contact_number = ? AND visit_date = ? AND time_visit = ?");
        pstmt->setString(1, login);
        pstmt->setString(2, contactNumber);
        pstmt->setString(3, visitDate);
        pstmt->setString(4, timeVisit);
        pstmt->setString(5, note);
        pstmt->setString(6, login);
        pstmt->setString(7, contactNumber);
        pstmt->setString(8, visitDate);
        pstmt->setString(9, timeVisit);
        pstmt->execute();
        delete pstmt;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL error: " << e.what() << endl;
        return false;
    }
}
