#ifndef FACULTY_H
#define FACULTY_H
#include "user.h"
class Faculty : User{
public:
    Faculty(int _employeeId, bool _isAdmin, QString _userName, QString _firstName,
        QString _lastName, QString _email);
private:
    int employeeId;
};
#endif // !FACULTY_H
