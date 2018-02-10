#ifndef USER_H
#define USER_H
#include <string>
#include <QString>
class User {
public:
    User(int _userId, QString _userName, QString _firstName, QString _lastName, QString _email, bool _isAdmin);
    int getUserId();
    QString getUsername();
    QString getFirstName();
    QString getLastName();
    QString getEmail();
    //QString email;




    bool getIsAdmin() const;

    void setUserId(int value);

    void setUsername(const QString value);

    void setFirstName(const QString value);

    void setLastName(const QString value);

    void setEmail(const QString value);

    void setIsAdmin(bool value);

    int userId;
    QString username;
    QString firstName;
    QString lastName;
    QString email;
    bool isAdmin;
private:

};
#endif // !USER_H
