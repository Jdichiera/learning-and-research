/*
Author: Jeramy Dichiera
Creation Date : 11/05/17
Modification Date : 11/06/17
FileName: Contact.h
Purpose: A class that is derived from the Person class
Input: 
Output:
Exceptions:
*/
#ifndef CONTACT_H
#define CONTACT_H
#include "person.h"
class Contact : public Person {
public:
	/*
	Contact()
	Purpose : An initilizer constructor for the Contact class.
	Input : Int and string variables to initialize the contact object.
	Output : An initialized contat object.
	*/
	Contact(int newContactNumber, std::string newPhoneNumber, std::string newFirstName,
		std::string newLastName, int newEmployeeNumber, std::string newProgramTeam);
	/*
	SetContactNumber()
	Purpose : A setter for the contactNumber class attribute
	Input : none
	Output : the int employeeNumber
	*/
	void setContactNumber(int newContactNumber);
	/*
	GetContactNumber()
	Purpose : A getter for the contactNumber class attribute
	Input : none
	Output : the int contactNumber
	*/
	int getContactNumber();
private:
	int contactNumber;
};
#endif // !CONTACT_H
