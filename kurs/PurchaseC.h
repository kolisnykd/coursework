#ifndef PURCHASEC_H
#define PURCHASEC_H
#include <string>
#include <cppconn/connection.h>
class PurchaseC {
public:
	int purchaseId;
	std::string login;
	std::string loginEmployee;
	int isbn;
	std::string date;
	std::string time;
	int quantity;
	double cost;
	int getPurchaseId() const;
	void setPurchaseId(int purchaseId);
	std::string getLogin() const;
	void setLogin(const std::string& login);
	std::string getLoginEmployee() const;
	void setLoginEmployee(const std::string& loginEmployee);
	int getIsbn() const;
	void setIsbn(int isbn);
	std::string getDate() const;
	void setDate(const std::string& date);
	std::string getTime() const;
	void setTime(const std::string& time);
	int getQuantity() const;
	void setQuantity(int quantity);
	double getCost() const;
	void setCost(double cost);
	bool saveToDatabase(sql::Connection* connection);
	bool loadFromDatabase(sql::Connection* connection);
	bool updateInDatabase(sql::Connection* connection);
};
#endif // PURCHASEC_H
