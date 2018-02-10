#ifndef PERSONALINFO_H
#define PERSONALINFO_H
#include <string>
class PersonalInfo {
public:
	/*PersonalInfo(int newRecordNumber, std::string newFirstName, std::string newLastName,
		int newAge, std::string newTelephoneNumber);*/
	PersonalInfo::PersonalInfo();
	std::string getFirstName();
	void setFirstName(std::string newFirstName);

	std::string getLastName();
	void setLastName(std::string newLastName);

	int getAge();
	void setAge(int newAge);

	std::string getTelephoneNumber();
	void setTelephoneNumber(std::string newTelephoneNumber);

private:
	std::string firstName;
	std::string lastName;
	int age;
	std::string telephoneNumber;
};
#endif // !PERSONALINFO_H
