/*
Author: Jeramy Dichiera
Creation Date : 11/05/17
Modification Date : 11/06/17
FileName: Person.h
Purpose: A class that holds a contacts personal and employment info objects
Input:  String and int variables for personal and employment informaton when using the initializer constructor.
Output: An object of class Person
Exceptions: None
*/
#ifndef PERSON_H
#define PERSON_H
#include "personal-info.h"
#include "employer-info.h"

class Person {
private:
	PersonalInfo personalInfo;
	EmployerInfo employerInfo;
public:
	/*
	Person()
	Purpose : A class constructor
	Input : strings and ints for each of the class object constructors
	Output : An initialized object of type Person
	*/
	Person(std::string newPhoneNumber, std::string newFirstName, std::string newLastName, 
		int newEmployeeNumber, std::string newProgramTeam);
	/*
	DisplayInfo()
	Purpose : Prints out the information for the Person object
	Input : none
	Output : none
	*/
	void displayInfo();
	/*
	ShortInfo()
	Purpose : Prints out the information for the Person object in a short format
	Input : none
	Output : none
	*/
	void shortInfo();

	/*
	GetPhoneNumber()
	Purpose : A getter for the phoneNumber class attribute
	Input : none
	Output : the string phoneNumber
	*/
	std::string getPhoneNumber();
	/*
	GetFirstName()
	Purpose : A getter for the firstName class attribute
	Input : none
	Output : the string firstName
	*/
	std::string getFirstName();
	/*
	GetLastName()
	Purpose : A getter for the lastName class attribute
	Input : none
	Output : the string lastName
	*/
	std::string getLastName();
	/*
	GetEmployeeNumber()
	Purpose : A getter for the employeeNumber class attribute
	Input : none
	Output : the int employeeNumber
	*/
	int getEmployeeNumber();
	/*
	GetProgramTeam()
	Purpose : A getter for the programTeam class attribute
	Input : none
	Output : the string programTeam
	*/
	std::string getProgramTeam();
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
	SetEmployeeNumber()
	Purpose : A getter for the employeeNumber class attribute
	Input : none
	Output : the int employeeNumber
	*/
	void setEmployeeNumber(int newEmployeeNumber);
	/*
	setProgramTeam()
	Purpose : A setter for the programTeam class attribute
	Input : a string programTeam
	Output : none
	*/
	void setProgramTeam(std::string newProgramTeam);
};
#endif // !PERSON_H
