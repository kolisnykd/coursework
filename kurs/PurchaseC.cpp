#include "PurchaseC.h"
#include <cppconn/prepared_statement.h>
using namespace std;
int PurchaseC::getPurchaseId() const {
    return purchaseId;
}
void PurchaseC::setPurchaseId(int purchaseId) {
    PurchaseC::purchaseId = purchaseId;
}
std::string PurchaseC::getLogin() const {
    return login;
}
void PurchaseC::setLogin(const std::string& login) {
    PurchaseC::login = login;
}
std::string PurchaseC::getLoginEmployee() const {
    return loginEmployee;
}
void PurchaseC::setLoginEmployee(const std::string& loginEmployee) {
    PurchaseC::loginEmployee = loginEmployee;
}
int PurchaseC::getIsbn() const {
    return isbn;
}
void PurchaseC::setIsbn(int isbn) {
    PurchaseC::isbn = isbn;
}
std::string PurchaseC::getDate() const {
    return date;
}
void PurchaseC::setDate(const std::string& date) {
    PurchaseC::date = date;
}
std::string PurchaseC::getTime() const {
    return time;
}
void PurchaseC::setTime(const std::string& time) {
    PurchaseC::time = time;
}
int PurchaseC::getQuantity() const {
    return quantity;
}
void PurchaseC::setQuantity(int quantity) {
    PurchaseC::quantity = quantity;
}
double PurchaseC::getCost() const {
    return cost;
}
void PurchaseC::setCost(double cost) {
    PurchaseC::cost = cost;
}
bool PurchaseC::saveToDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmtPurchase = connection->prepareStatement("INSERT INTO purchase (login, login_employee) VALUES (?, ?)");
        pstmtPurchase->setString(1, login);
        pstmtPurchase->setString(2, loginEmployee);
        pstmtPurchase->execute();
        delete pstmtPurchase; 
        sql::PreparedStatement* pstmtBook = connection->prepareStatement("INSERT INTO purchase_book (isbn, date, time, quantity, cost) VALUES (?, ?, ?, ?, ?)");
        pstmtBook->setInt(1, isbn);
        pstmtBook->setString(2, date);
        pstmtBook->setString(3, time);
        pstmtBook->setInt(4, quantity);
        pstmtBook->setDouble(5, cost);
        pstmtBook->execute();
        delete pstmtBook; 
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL error: " << e.what() << endl;
        return false;
    }
}
bool PurchaseC::loadFromDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmtPurchase = connection->prepareStatement("SELECT * FROM purchase WHERE purchase_id = ?");
        pstmtPurchase->setInt(1, purchaseId);
        sql::ResultSet* resultSetPurchase = pstmtPurchase->executeQuery();
        if (resultSetPurchase->next()) {
            login = resultSetPurchase->getString("login");
            loginEmployee = resultSetPurchase->getString("login_employee");
        }
        delete pstmtPurchase;
        delete resultSetPurchase;
        sql::PreparedStatement* pstmtBook = connection->prepareStatement("SELECT * FROM purchase_book WHERE purchase_id = ?");
        pstmtBook->setInt(1, purchaseId); 
        sql::ResultSet* resultSetBook = pstmtBook->executeQuery();
        if (resultSetBook->next()) {
            isbn = resultSetBook->getInt("isbn");
            date = resultSetBook->getString("date");
            time = resultSetBook->getString("time");
            quantity = resultSetBook->getInt("quantity");
            cost = resultSetBook->getDouble("cost");
        }
        delete pstmtBook;
        delete resultSetBook;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL error: " << e.what() << endl;
        return false;
    }
}
bool PurchaseC::updateInDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmtPurchase = connection->prepareStatement("UPDATE purchase SET login = ?, login_employee = ? WHERE purchase_id = ?");
        pstmtPurchase->setString(1, login);
        pstmtPurchase->setString(2, loginEmployee);
        pstmtPurchase->setInt(3, purchaseId);
        pstmtPurchase->execute();
        delete pstmtPurchase;
        sql::PreparedStatement* pstmtBook = connection->prepareStatement("UPDATE purchase_book SET isbn = ?, date = ?, time = ?, quantity = ?, cost = ? WHERE purchase_id = ?");
        pstmtBook->setInt(1, isbn);
        pstmtBook->setString(2, date);
        pstmtBook->setString(3, time);
        pstmtBook->setInt(4, quantity);
        pstmtBook->setDouble(5, cost);
        pstmtBook->setInt(6, purchaseId);
        pstmtBook->execute();
        delete pstmtBook;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL error: " << e.what() << endl;
        return false;
    }
}