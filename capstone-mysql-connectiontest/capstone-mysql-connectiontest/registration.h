#ifndef REGISTRATION_H
#define REGISTRATION_H
#include <string>
#include <vector>
#include "course.h"
class Registration {
public:
	Registration();
	std::vector<Course> getRegistration();
	void addClass(Course newClass);
	void removeClass(Course className);
private:
	std::vector<Course> courseList;

};
#endif // !REGISTRATION_H
