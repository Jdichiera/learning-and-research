/*
Author: Jeramy Dichiera
Creation Date : 11/05/17
Modification Date : 11/06/17
FileName: person.cpp
Purpose: The implementation file for the person class
Input: None
Output: None
Exceptions: None
*/
#include "person.h"

Person::Person(std::string newPhoneNumber, std::string newFirstName, std::string newLastName, int newEmployeeNumber, std::string newProgramTeam)
{
	personalInfo.setPhoneNumber(newPhoneNumber);
	personalInfo.setFirstName(newFirstName);
	personalInfo.setLastName(newLastName);
	employerInfo.setEmployeeNumber(newEmployeeNumber);
	employerInfo.setProgramTeam(newProgramTeam);
}

void Person::displayInfo()
{
	personalInfo.displayInfo();
	employerInfo.displayInfo();
}

void Person::shortInfo()
{
	std::cout << "Employee Number- " << employerInfo.getEmployeeNumber() << " | Name- " << personalInfo.getLastName() << ", " << personalInfo.getFirstName();
}

std::string Person::getPhoneNumber()
{
	return personalInfo.getPhoneNumber();
}

std::string Person::getFirstName()
{
	return personalInfo.getPhoneNumber();;
}

std::string Person::getLastName()
{
	return personalInfo.getLastName();
}

int Person::getEmployeeNumber()
{
	return employerInfo.getEmployeeNumber();
}

std::string Person::getProgramTeam()
{
	return employerInfo.getProgramTeam();
}

void Person::setPhoneNumber(std::string newPhoneNumber)
{
	personalInfo.setPhoneNumber(newPhoneNumber);
}

void Person::setFirstName(std::string newFirstName)
{
	personalInfo.setFirstName(newFirstName);
}

void Person::setLastName(std::string newLastName)
{
	personalInfo.setLastName(newLastName);
}

void Person::setEmployeeNumber(int newEmployeeNumber)
{
	employerInfo.setEmployeeNumber(newEmployeeNumber);
}

void Person::setProgramTeam(std::string newProgramTeam)
{
	employerInfo.setProgramTeam(newProgramTeam);
}
