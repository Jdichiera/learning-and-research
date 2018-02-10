#ifndef COURSE_H
#define COURSE_H
#include <QString>
//#include <QDate>
class Course {
public:
    Course(int _courseId, QString _registrationDate, QString _completionDate,
           QString _courseName, QString courseStatus, QString _courseDescription,
           int _courseCredits, QString _courseType, double _courseGrade, QString _semester);

    int getCourseId() const;
    QString getRegistrationDate() const;
    QString getCompletionDate() const;
    QString getCourseName() const;
    QString getCourseStatus() const;
    QString getCourseDescription() const;
    int getCourseCredits() const;
    QString getCourseType() const;
    double getCourseGrade() const;
    QString getSemester() const;

    void setCourseId(int value);

    void setRegistrationDate(const QString value);

    void setCompletionDate(const QString value);

    void setCourseName(const QString value);

    void setCourseStatus(const QString value);

    void setCourseDescription(const QString value);

    void setCourseCredits(int value);

    void setCourseType(const QString value);

    void setCourseGrade(double value);

    void setSemester(const QString value);

private:
    int courseId;
    QString registrationDate;
    QString completionDate;
    QString courseName;
    QString courseStatus;
    QString courseDescription;
    int courseCredits;
    QString courseType;
    double courseGrade;
    QString semester;
};
#endif // !COURSE_H
