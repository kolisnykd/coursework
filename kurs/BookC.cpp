#include "BookC.h"
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
using namespace std;
int BookC::getIsbn() const {
    return isbn;
}
void BookC::setIsbn(int isbn) {
    BookC::isbn = isbn;
}
std::string BookC::getName() const {
    return name;
}
void BookC::setName(const std::string& name) {
    BookC::name = name;
}
std::string BookC::getAuthor() const {
    return author;
}
void BookC::setAuthor(const std::string& author) {
    BookC::author = author;
}
float BookC::getCost() const {
    return cost;
}
void BookC::setCost(float cost) {
    BookC::cost = cost;
}
std::string BookC::getGenre() const {
    return genre;
}
void BookC::setGenre(const std::string& genre) {
    BookC::genre = genre;
}
std::string BookC::getPublishingHouse() const {
    return publishingHouse;
}
void BookC::setPublishingHouse(const std::string& publishingHouse) {
    BookC::publishingHouse = publishingHouse;
}
bool BookC::saveToDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("INSERT INTO book VALUES (?, ?, ?, ?, ?, ?)");
        pstmt->setInt(1, isbn);
        pstmt->setString(2, name);
        pstmt->setString(3, author);
        pstmt->setInt(4, cost);
        pstmt->setString(5, genre);
        pstmt->setString(6, publishingHouse);
        pstmt->execute();
        delete pstmt;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL error: " << e.what() << endl;
        return false;
    }
}
bool BookC::loadFromDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("SELECT * FROM book WHERE isbn = ?");
        pstmt->setInt(1, isbn);
        sql::ResultSet* resultSet = pstmt->executeQuery();
        if (resultSet->next()) {
            name = resultSet->getString("name");
            author = resultSet->getString("author");
            cost = resultSet->getInt("cost");
            genre = resultSet->getString("genre");
            publishingHouse = resultSet->getString("publishing_house");
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
bool BookC::updateInDatabase(sql::Connection* connection) {
    try {
        sql::PreparedStatement* pstmt = connection->prepareStatement("UPDATE book SET name = ?, author = ?, cost = ?, genre = ?, publishing_house = ? WHERE isbn = ?");
        pstmt->setString(1, name);
        pstmt->setString(2, author);
        pstmt->setInt(3, cost);
        pstmt->setString(4, genre);
        pstmt->setString(5, publishingHouse);
        pstmt->setInt(6, isbn);
        pstmt->execute();
        delete pstmt;
        return true;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL error: " << e.what() << endl;
        return false;
    }
}
