#ifndef EMPLOYMENTINFO_H
#define EMPLOYMENTINFO_H
#include <string>
class EmploymentInfo {
public:
	void setEmployerName(std::string newEmployerName);
	std::string getEmployerName();
private:
	std::string employerName;
};
#endif