#ifndef VISITC_H
#define VISITC_H
#include <string>
#include <cppconn/connection.h>
class VisitC {
public:
	std::string login;
	std::string contactNumber;
	std::string note;
	std::string visitDate;
	std::string timeVisit;
	std::string getLogin() const;
	void setLogin(const std::string& login);
	std::string getContactNumber() const;
	void setContactNumber(const std::string& contactNumber);
	std::string getNote() const;
	void setNote(const std::string& note);
	std::string getVisitDate() const;
	void setVisitDate(const std::string& visitDate);
	std::string getTimeVisit() const;
	void setTimeVisit(const std::string& timeVisit);
	bool saveToDatabase(sql::Connection* connection);
	bool loadFromDatabase(sql::Connection* connection);
	bool updateInDatabase(sql::Connection* connection);
};
#endif // VISITC_H
