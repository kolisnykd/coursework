#ifndef BOOKSTORE_H
#define BOOKSTORE_H
#include <string>
#include <cppconn/connection.h>
class BookstoreC {
public:
	std::string contactNumber;
	std::string name;
	std::string address;
	std::string workSchedule;
	// Member functions for getters, setters, database operations
	std::string getContactNumber() const;
	void setContactNumber(const std::string& contactNumber);
	std::string getName() const;
	void setName(const std::string& name);
	std::string getAddress() const;
	void setAddress(const std::string& address);
	std::string getWorkSchedule() const;
	void setWorkSchedule(const std::string& workSchedule);
	bool saveToDatabase(sql::Connection* connection);
	bool loadFromDatabase(sql::Connection* connection);
	bool updateInDatabase(sql::Connection* connection);
};
#endif // BOOKSTORE_H
