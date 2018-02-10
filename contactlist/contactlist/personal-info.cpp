/*
Author: Jeramy Dichiera
Creation Date : 11/05/17
Modification Date : 11/06/17
FileName: personal-info.cpp
Purpose: The implementation file for the personal-info class
Input: None
Output: None
Exceptions: None
*/
#include "personal-info.h"

PersonalInfo::PersonalInfo() {
	phoneNumber = "";
	firstName = "";
	lastName = "";
}
PersonalInfo::PersonalInfo(std::string newPhoneNumber, std::string newFirstName, std::string newLastName)
{
	phoneNumber = newPhoneNumber;
	firstName = newFirstName;
	lastName = newLastName;
}

void PersonalInfo::setPhoneNumber(std::string newPhoneNumber)
{
	phoneNumber = newPhoneNumber;
}

std::string PersonalInfo::getPhoneNumber()
{
	return phoneNumber;
}

void PersonalInfo::setFirstName(std::string newFirstName)
{
	firstName = newFirstName;
}

std::string PersonalInfo::getFirstName()
{
	return firstName;
}

void PersonalInfo::setLastName(std::string newLastName)
{
	lastName = newLastName;
}

std::string PersonalInfo::getLastName()
{
	return lastName;
}

void PersonalInfo::displayInfo()
{
	std::cout << "\n Name: " << lastName << ", " << firstName;
	std::cout << "\n Telephone: " << phoneNumber;
}
