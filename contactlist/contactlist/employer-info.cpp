/*
Author: Jeramy Dichiera
Creation Date : 11/05/17
Modification Date : 11/06/17
FileName: Employer-info.cpp
Purpose: The implementation file for the Employer-Info class
Input: None
Output: None
Exceptions: None
*/
#include "employer-info.h"

EmployerInfo::EmployerInfo()
{
	employeeNumber = 0;
	programTeam = "";
}

EmployerInfo::EmployerInfo(int newEmployeeNumber, std::string newProgramTeam)
{
	employeeNumber = newEmployeeNumber;
	programTeam = newProgramTeam;
}

void EmployerInfo::setEmployeeNumber(int newEmployeeNumber)
{
	employeeNumber = newEmployeeNumber;
}

int EmployerInfo::getEmployeeNumber()
{
	return employeeNumber;
}

void EmployerInfo::setProgramTeam(std::string newProgramTeam)
{
	programTeam = newProgramTeam;
}

std::string EmployerInfo::getProgramTeam()
{
	return programTeam;
}

void EmployerInfo::displayInfo()
{
	std::cout << "\n Employee Number: " << getEmployeeNumber();
	std::cout << "\n Program Team: " << getProgramTeam();
}
