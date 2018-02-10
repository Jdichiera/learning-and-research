#ifndef USER_H
#define USER_H
#include <string>
class User {
public:
	User(bool admin, int newUserId, std::string newUserName, std::string newFirstName, 
		std::string newLastName, std::string newEmail);
	bool getAdmin();

	int getUserId();
	std::string getUserName();
	std::string getFirstName();
	std::string getLastName();
	std::string getEmail();

	int getUserId();
	std::string setUserName();
	std::string setFirstName();
	std::string setLastName();
	std::string setEmail();

private:
	bool isAdmin;
	int userId;
	std::string userName;
	std::string firstName;
	std::string lastName;
	std::string email;
};
#endif // !USER_H
