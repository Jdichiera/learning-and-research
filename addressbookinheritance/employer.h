#include <iostream>
class Employer {
public:
	void print() {
		std::cout << "Employee Number: " + employeeNumber;
		std::cout << "Employee Type: " + employmentType;
	}
	Employer(int newEmployeeNumber) {
		employeeNumber = newEmployeeNumber;
		employmentType = "base";
	}
//private:
	int employeeNumber;
	std::string employmentType;
};