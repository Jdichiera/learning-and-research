#include "faculty.h"

Faculty::Faculty(int _employeeId, bool _isAdmin,
                 QString _userName, QString _firstName,
                 QString _lastName, QString _email)
    : User(_employeeId, _userName, _firstName, _lastName, _email, true)

{
    employeeId = _employeeId;
}
