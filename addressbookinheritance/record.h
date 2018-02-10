/*
* File:   record.h
* Author: Jeramy Dichiera
*
* Created on October 7, 2017, 12:07 PM
*/
#ifndef RECORD_H
#define RECORD_H
#include"personal-info.h"
#include "employment-info.h"
#include "manufacturing.h"
class Record {
public:
	Record();
	Record(int newRecordNumber, std::string newFirstName, std::string newLastName,
		int newAge, std::string newTelephoneNumber, std::string newEmployerName);
	int getRecordNumber();

	void printRecord();
	void updateFirstName(std::string newFirstName);
	void updateLastName(std::string newLastName);
	void updateAge(int newAge);
	void updateTelephonenumber(std::string newTelephonenumber);
	void updateEmployer(std::string newEmployer);
	void setManufacturingZ(int newNumber)

	{

		employer1.setZ(newNumber);         //error since employer1 doesn't recognize the Manufacturing object's setZ() method

	}

private:
	int recordNumber;
	PersonalInfo personalInfo;
	EmploymentInfo employmentInfo;
	Manufacturing employer1;
	
};


#endif /* RECORD_H */

