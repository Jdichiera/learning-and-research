#include "personal-info.h"

//PersonalInfo::PersonalInfo(int newRecordNumber, std::string newFirstName, std::string newLastName,
//	int newAge, std::string newTelephoneNumber)
//{
//	firstName = newFirstName;
//	lastName = newLastName;
//	age = newAge;
//	telephoneNumber = newTelephoneNumber;
//}
PersonalInfo::PersonalInfo() {
	firstName = "";
	lastName = "";
	age = 0;
	telephoneNumber = "000-000-0000";
}
std::string PersonalInfo::getFirstName() {
	return firstName;
}
std::string PersonalInfo::getLastName() {
	return lastName;
}
void PersonalInfo::setFirstName(std::string newFirstName) {
	firstName = newFirstName;
}
void PersonalInfo::setLastName(std::string newLastName) {
	lastName = newLastName;
}

int PersonalInfo::getAge() {
	return age;
}
void PersonalInfo::setAge(int newAge) {
	age = newAge;
}

std::string PersonalInfo::getTelephoneNumber() {
	return telephoneNumber;
}
void PersonalInfo::setTelephoneNumber(std::string newTelephoneNumber) {
	telephoneNumber = newTelephoneNumber;
}