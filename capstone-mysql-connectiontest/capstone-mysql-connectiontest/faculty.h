#ifndef FACULTY_H
#define FACULTY_H
#include "user.h"
class Faculty {
public:
	Faculty(int employeeId, bool admin, int newUserId, std::string newUserName, std::string newFirstName,
		std::string newLastName, std::string newEmail);
private:
	int employeeId;
};
#endif // !FACULTY_H
