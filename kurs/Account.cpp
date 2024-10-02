#include "account.h"
#include <cppconn/prepared_statement.h>
using namespace std;
Account::Account(string login, string password, int rights)
    : login(move(login)), password(move(password)), rights(rights) {}
std::string Account::getLogin() const {
    return login;
}
std::string Account::getPassword() const {
    return password;
}
int Account::getRights() const {
    return rights;
}
void Account::setLogin(const std::string& login) {
    Account::login = login;
}
void Account::setPassword(const std::string& password) {
    Account::password = password;
}
void Account::setRights(int rights) {
    Account::rights = rights;
}
bool Account::saveToDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("INSERT INTO login VALUES (?, ?, ?)");
        pstmt->setString(1, login);
        pstmt->setString(2, password);
        pstmt->setInt(3, rights);
        pstmt->execute();
        delete pstmt;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL error: " << e.what() << endl;
        return false;
    }
}
bool Account::loadFromDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("SELECT * FROM login WHERE login = ?");
        pstmt->setString(1, login);
        sql::ResultSet* resultSet = pstmt->executeQuery();
        if (resultSet->next()) {
            password = resultSet->getString("password");
            rights = resultSet->getInt("rights");
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
bool Account::updateInDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("UPDATE login SET password = ?, rights = ? WHERE login = ?");
        pstmt->setString(1, password);
        pstmt->setInt(2, rights);
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
