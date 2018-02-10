/*
Author: Jeramy Dichiera
Creation Date : 11/05/17
Modification Date : 11/06/17
FileName: contact.cpp
Purpose: The implementation file for the Contact class
Input: None
Output: None
Exceptions: None
*/
#include "contact.h"

Contact::Contact(int newContactNumber, std::string newPhoneNumber, std::string newFirstName, 
	std::string newLastName, int newEmployeeNumber, std::string newProgramTeam) 
	: Person(newPhoneNumber, newFirstName, newLastName, newEmployeeNumber, newProgramTeam)
{
	contactNumber = newContactNumber;
}

void Contact::setContactNumber(int newContactNumber)
{
	contactNumber = newContactNumber;
}

int Contact::getContactNumber()
{
	return contactNumber;
}
