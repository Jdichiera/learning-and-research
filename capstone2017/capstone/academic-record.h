#ifndef ACADEMICRECORD_H
#define ACADEMICRECORD_H
#include <string>
#include <vector>
#include "course.h"
class AcademicRecord {
public:
    AcademicRecord();
    std::vector<Course> getCourseList();
    void addClass(Course _class);
    void PrintRecord();
    QString GetCourseName(int _recordNumber);
    int Size();
    std::vector<Course> courseList;
private:

};
#endif // !ACADEMICRECORD_H
