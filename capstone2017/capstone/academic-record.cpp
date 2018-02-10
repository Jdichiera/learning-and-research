#include "academic-record.h"
#include <QDebug>

AcademicRecord::AcademicRecord()
{
    std::vector<Course> courseList;
}

std::vector<Course> AcademicRecord::getCourseList()
{
    return courseList;
}

void AcademicRecord::addClass(Course _class)
{
    courseList.push_back(_class);
}

void AcademicRecord::PrintRecord()
{
    int size = courseList.size();
    for(int i = 0; i < size; i++){
        QString course = courseList.at(i).getCourseName();
        qDebug() << "Course: " << course;
    }
}

QString AcademicRecord::GetCourseName(int _recordNumber)
{
    return courseList.at(_recordNumber).getCourseName();
}

int AcademicRecord::Size()
{
    if(courseList.size() <= 0 ){
        return 0;
    }
    else {
        return courseList.size();
    }
}


