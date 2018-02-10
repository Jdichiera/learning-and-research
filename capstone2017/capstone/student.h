#ifndef STUDENT_H
#define STUDENT_H
#include "user.h"
#include "academic-record.h"
#include <QString>
class Student : public User {
public:
    Student();
    Student(int _userId, QString _userName, QString _firstName,
            QString _lastName, QString _email, double _gpa, AcademicRecord _academicRecord);
    double getGpa();
    AcademicRecord getAcademicRecord();
    Print();

    void AddCourse(Course _course);
    AcademicRecord academicRecord;
    void setAcademicRecord(const AcademicRecord value);

    void CalculateGpa();
    void setGpa(double value);
    void CalculateCourseLoad();

    int getCourseLoad() const;
    void setCourseLoad(int value);

private:
    double gpa;
    int courseLoad;

};
#endif // !STUDENT_H
