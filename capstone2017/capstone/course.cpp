#include "course.h"

Course::Course(int _courseId, QString _registrationDate, QString _completionDate,
               QString _courseName, QString _courseStatus, QString _courseDescription,
               int _courseCredits, QString _courseType, double _courseGrade, QString _semester)
{
    courseId = _courseId;
    registrationDate = _registrationDate;
    completionDate = _completionDate;
    courseName = _courseName;
    courseStatus = _courseStatus;
    courseDescription = _courseDescription;
    courseCredits = _courseCredits;
    courseType = _courseType;
    courseGrade = _courseGrade;
    semester = _semester;
}

int Course::getCourseId() const
{
    return courseId;
}


QString Course::getRegistrationDate() const
{
    return registrationDate;
}

QString Course::getCompletionDate() const
{
    return completionDate;
}

QString Course::getCourseName() const
{
    return courseName;
}

QString Course::getCourseStatus() const
{
    return courseStatus;
}

QString Course::getCourseDescription() const
{
    return courseDescription;
}

int Course::getCourseCredits() const
{
    return courseCredits;
}

QString Course::getCourseType() const
{
    return courseType;
}

double Course::getCourseGrade() const
{
    return courseGrade;
}

QString Course::getSemester() const
{
    return semester;
}

void Course::setCourseId(int value)
{
    courseId = value;
}

void Course::setRegistrationDate(const QString value)
{
    registrationDate = value;
}

void Course::setCompletionDate(const QString value)
{
    completionDate = value;
}

void Course::setCourseName(const QString value)
{
    courseName = value;
}

void Course::setCourseStatus(const QString value)
{
    courseStatus = value;
}

void Course::setCourseDescription(const QString value)
{
    courseDescription = value;
}

void Course::setCourseCredits(int value)
{
    courseCredits = value;
}

void Course::setCourseType(const QString value)
{
    courseType = value;
}

void Course::setCourseGrade(double value)
{
    courseGrade = value;
}

void Course::setSemester(const QString value)
{
    semester = value;
}
