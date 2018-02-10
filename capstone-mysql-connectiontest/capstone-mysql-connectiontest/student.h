#ifndef STUDENT_H
#define STUDENT_H
#include "user.h"
#include "registration.h"
class Student : User {
public:
	Student(double newGpa, Registration registration, bool admin, int newUserId, std::string newUserName, 
		std::string newFirstName, std::string newLastName, std::string newEmail);
	double getGpa();
	Registration getRegistration();
private:
	double gpa;
	Registration registration;

};
#endif // !STUDENT_H
