#include "user.h"

User::User(int _userId, QString _username, QString _firstName, QString _lastName, QString _email, bool _isAdmin)
{
    userId = _userId;
    username = _username;
    firstName = _firstName;
    lastName = _lastName;
    email = _email;
    isAdmin = _isAdmin;
}


int User::getUserId()
{
    return userId;
}

QString User::getUsername()
{
    return username;
}

QString User::getFirstName()
{
    return firstName;
}

QString User::getLastName()
{
    return lastName;
}

QString User::getEmail()
{
    return email;
}

bool User::getIsAdmin() const
{
    return isAdmin;
}

void User::setUserId(int value)
{
    userId = value;
}

void User::setUsername(const QString value)
{
    username = value;
}

void User::setFirstName(const QString value)
{
    firstName = value;
}

void User::setLastName(const QString value)
{
    lastName = value;
}

void User::setEmail(const QString value)
{
    email = value;
}

void User::setIsAdmin(bool value)
{
    isAdmin = value;
}




