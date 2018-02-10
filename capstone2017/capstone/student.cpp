#include "student.h"
#include <QDebug>

Student::Student() : User(000, QString(), QString(), QString(), QString(), false){
    academicRecord = AcademicRecord();
    gpa = 0;
    courseLoad = 0;
}
Student::Student(int _userId, QString _userName, QString _firstName,
                 QString _lastName, QString _email, double _gpa,
                 AcademicRecord _academicRecord)
    : User(_userId, _userName, _firstName, _lastName, _email, false)
{
    academicRecord = _academicRecord;
    gpa = _gpa;
}

double Student::getGpa()
{
    return gpa;
}

AcademicRecord Student::getAcademicRecord(){
    return academicRecord;
}
Student::Print()
{
    qDebug() << "ID: " << getUserId() << " UN: " << getUsername() << " EM: "
            << getEmail() << " FN: " << getFirstName() << " LN: "
            << getLastName() << " Admin: " << getIsAdmin() << " GPA: "
            << getGpa();
}

void Student::AddCourse(Course _course)
{
    academicRecord.addClass(_course);
}

void Student::setAcademicRecord(const AcademicRecord value)
{
    academicRecord = value;
}

void Student::CalculateGpa()
{
    std::vector<Course> courseList(academicRecord.getCourseList());
    double gradeTally = 0.0;
    int creditTally = 0;
    double gpa = 0.0;
    for(auto course : courseList){
        if(course.getCourseStatus() == "p"){
            gradeTally += course.getCourseGrade() * course.getCourseCredits();
            creditTally += course.getCourseCredits();
        }
    }
    gpa = gradeTally / creditTally;
    setGpa(gpa);
}

void Student::setGpa(double value)
{
    gpa = value;
}

void Student::CalculateCourseLoad()
{
    std::vector<Course> courseList(academicRecord.getCourseList());
    int courseLoad = 0;
    for(auto course : courseList){
        if(course.getCourseStatus() == "i"){
            courseLoad += course.getCourseCredits();
        }
    }
    setCourseLoad(courseLoad);
}

int Student::getCourseLoad() const
{
    return courseLoad;
}

void Student::setCourseLoad(int value)
{
    courseLoad = value;
}
