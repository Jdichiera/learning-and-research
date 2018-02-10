/*
Author: Jeramy Dichiera
Creation Date : 11/05/17
Modification Date : 11/06/17
FileName: EmployerInfo.h
Purpose: A class that holds employment info for the person object
Input: none when using the default constructor. Int and string variable inputs when using the initializer constructor
Output: An object of type Employer
Exceptions: None
*/
#ifndef EMPLOYERINFO_H
#define EMPLOYERINFO_H
#include <string>
#include <iostream>
class EmployerInfo {
private:
	int employeeNumber;
	std::string programTeam;
public:
	/*
	EmployerInfo()
	Purpose : EmployerInfo class default constructor
	Input : None
	Output : a EmployerInfo object
	*/
	EmployerInfo();
	/*
	EmployerInfo()
	Purpose : EmployerInfo class initializer constructor
	Input : int employeeNumber and string programTeam
	Output : an initialized EmployerInfo object
	*/
	EmployerInfo(int newEmployeeNumber, std::string newProgramTeam);
	/*
	SetEmployeeNumber()
	Purpose : A getter for the employeeNumber class attribute
	Input : none
	Output : the int employeeNumber
	*/
	void setEmployeeNumber(int newEmployeeNumber);
	/*
	GetEmployeeNumber()
	Purpose : A getter for the employeeNumber class attribute
	Input : none
	Output : the int employeeNumber
	*/
	int getEmployeeNumber();
	/*
	setProgramTeam()
	Purpose : A setter for the programTeam class attribute
	Input : a string programTeam
	Output : none
	*/
	void setProgramTeam(std::string newProgramTeam);
	/*
	SetPhoneNumber()
	Purpose : A setter for the phoneNumber class attribute
	Input : string phoneNumber
	Output : none
	*/
	std::string getProgramTeam();
	/*
	DisplayInfo()
	Purpose : Prints out the information for the employerInfo object
	Input : none
	Output : none
	*/
	void displayInfo();
};
#endif // !EMPLOYERINFO_H
