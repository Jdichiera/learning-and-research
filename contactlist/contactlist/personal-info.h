/*
	Author: Jeramy Dichiera
	Creation Date : 11/05/17
	Modification Date : 11/06/17
	FileName: personal-info.h
	Purpose: A class for holding a contacts personal information
	Input: None when using the default constructor. String variables for class attributes when using the initializer constructor.
	Output: An object of type PersonalInfo
	Exceptions: None
*/

#ifndef PERSONALINFO_H
#define PERSONALINFO_H
#include <string>
#include <iostream>
class PersonalInfo {
protected:
	std::string phoneNumber;
	std::string firstName;
	std::string lastName;
public:
	/*
		PersonalInfo()
		Purpose : PersonalInfo class default constructor
		Input : None
		Output : a PersonalInfo object
	*/
	PersonalInfo();
	/*
		PersonalInfo()
		Purpose : PersonalInfo class regular constructor 
		Input : Strings for phone number, first name, and last name
		Output : an initialized PersonalInfo object
	*/
	PersonalInfo(std::string newPhoneNumber, std::string newFirstName, std::string newLastName);
	/*
		SetPhoneNumber()
		Purpose : A setter for the phoneNumber class attribute
		Input : string phoneNumber
		Output : none
	*/
	void setPhoneNumber(std::string newPhoneNumber);
	/*
		SetFirstName()
		Purpose : A setter for the firstName class attribute
		Input : a string firstName
		Output : none
	*/
	void setFirstName(std::string newFirstName);
	/*
		SetLastName()
		Purpose : A setter for the lastName class attribute
		Input : a string lastName
		Output : none
	*/
	void setLastName(std::string newLastName);
	/*
		GetFirstName()
		Purpose : A getter for the firstName class attribute
		Input : none
		Output : the string firstName
	*/
	std::string getFirstName();
	/*
	GetPhoneNumber()
	Purpose : A getter for the phoneNumber class attribute
	Input : none
	Output : the string phoneNumber
	*/
	std::string getPhoneNumber();
	/*
	GetLastName()
	Purpose : A getter for the lastName class attribute
	Input : none
	Output : the string lastName
	*/
	std::string getLastName();
	/*
	DisplayInfo()
	Purpose : Prints out the information for the personalInfo object
	Input : none
	Output : none
	*/
	void displayInfo();
};
#endif // !PERSONALINFO_H
