
#include "record.h"

/*
* File:   record.cpp
* Author: Jeramy Dichiera
*
* Created on October 7, 2017, 12:07 PM
*/
#include "record.h"
#include <iostream>

//Record::Record() {
//	recordNumber = 0;
//	firstName = "";
//	lastName = "";
//	age = 0;
//	telephoneNumber = "";
//}

Record::Record(int newRecordNumber, std::string newFirstName, std::string newLastName,
	int newAge, std::string newTelephoneNumber, std::string newEmployerName) {
	//PersonalInfo personal(newRecordNumber, newFirstName, newLastName, newAge, newTelephoneNumber);
	recordNumber = newRecordNumber;
	personalInfo.setAge(newAge);
	personalInfo.setFirstName(newFirstName);
	personalInfo.setLastName(newLastName);
	personalInfo.setTelephoneNumber(newTelephoneNumber);
	employmentInfo.setEmployerName(newEmployerName);
	
}
void Record::updateFirstName(std::string newFirstName) {
	personalInfo.setFirstName(newFirstName);
}
void Record::updateLastName(std::string newLastName) {
	personalInfo.setFirstName(newLastName);
}
void Record::updateAge(int newAge)
{
	personalInfo.setAge(newAge);
}
void Record::updateTelephonenumber(std::string newTelephonenumber)
{
	personalInfo.setTelephoneNumber(newTelephonenumber);
}
void Record::updateEmployer(std::string newEmployer)
{
	employmentInfo.setEmployerName(newEmployer);
}
int Record::getRecordNumber() {
	return recordNumber;
}


void Record::printRecord() {
	std::cout << "\n\t-- Record " << recordNumber << " --";
	std::cout << "\n\t  Name : " << personalInfo.getLastName() << " " << personalInfo.getFirstName();
	std::cout << "\n\t  Age : " << personalInfo.getAge();
	std::cout << "\n\t  Number : " << personalInfo.getTelephoneNumber();
	std::cout << "\n\t  Employer : " << employmentInfo.getEmployerName();
}
