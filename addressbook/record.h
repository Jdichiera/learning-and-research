/*
* File:   record.h
* Author: Jeramy Dichiera
*
* Created on October 7, 2017, 12:07 PM
*/

#include <string>
#ifndef RECORD_H
#define RECORD_H

class Record {
public:
	Record();
	Record(int newRecordNumber, std::string newFirstName, std::string newLastName,
		int newAge, std::string newTelephoneNumber);
	int getRecordNumber();

	std::string getFirstName();
	void setFirstName(std::string newFirstName);

	std::string getLastName();
	void setLastName(std::string newLastName);

	int getAge();
	void setAge(int newAge);

	std::string getTelephoneNumber();
	void setTelephoneNumber(std::string newTelephoneNumber);

	void printRecord();

private:
	int recordNumber;
	std::string firstName;
	std::string lastName;
	int age;
	std::string telephoneNumber;
};


#endif /* RECORD_H */

