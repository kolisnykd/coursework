#ifndef BOOKC_H
#define BOOKC_H
#include <string>
#include <cppconn/connection.h>
class BookC {
public:
	int isbn;
	std::string name;
	std::string author;
	float cost;
	std::string genre;
	std::string publishingHouse;
	// Member functions for getters, setters, and database operations
	int getIsbn() const;
	void setIsbn(int isbn);
	std::string getName() const;
	void setName(const std::string& name);
	std::string getAuthor() const;
	void setAuthor(const std::string& author);
	float getCost() const;
	void setCost(float cost);
	std::string getGenre() const;
	void setGenre(const std::string& genre);
	std::string getPublishingHouse() const;
	void setPublishingHouse(const std::string& publishingHouse);
	bool saveToDatabase(sql::Connection* connection);
	bool loadFromDatabase(sql::Connection* connection);
	bool updateInDatabase(sql::Connection* connection);
};
#endif // BOOKC_H
