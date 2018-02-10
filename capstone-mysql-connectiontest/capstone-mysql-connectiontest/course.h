#ifndef COURSE_H
#define COURSE_H
#include <string>
class Course {
public:
	Course(int newCourseId, std::string newName, std::string newDescription, int newCredits, bool online);
	int getCourseId();
	std::string getName();
	std::string getDescription();
	int getCredits();
	bool isOnline();

private:
	int courseId;
	std::string name;
	std::string description;
	int credits;
	bool isOnline;
};
#endif // !COURSE_H
