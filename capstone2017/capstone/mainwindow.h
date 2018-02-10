#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <database.h>
#include "student.h"
#include "faculty.h"
#include "dialog.h"


enum Page {
    LOGINSTUDENT    = 0,
    LOGINDATABASE   = 1,
    LOGINFACULTY    = 2,
    SCREENDATABASE  = 3,
    SCREENSTUDENT   = 4,
    SCREENFACULTY   = 5,
    SCREENLOGOUT    = 6
};

namespace Ui {

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    QString ExpandCourseType(QString _type);
    QString ExpandCourseStatus(QString _status);
    void GotoPage(Page page);

    // Login

    // Set values on student page
    void GUISetStudent();
    void GUISetCurrentRegistration();
    void GUISetOpenCoursesTab(std::vector<Course> _openCourses);
    void GUISetRegistrationTab(std::vector<Course> _openCourses);
    void GUISetCourseHistoryTab();
    std::vector<Course> GetOpenCourses();
    bool AttemptLogin(QString _username, QString _password);
    void GetStudentObject(QString _username);
    AcademicRecord GetAcademicRecord(int _studentId);
    void AddCourse();
    ~MainWindow();

private slots:
    // Student Login Page
    void on_btnLogin_clicked();

    // DB Admin Page
    void on_btnDbAdminLogout_clicked();
    void on_btnDbAdminDropTable_clicked();
    void on_btnDbAdminAddTables_clicked();
    void on_btnDbAdminSeedTables_clicked();

    // Student Page
    void on_btnDbloginBack_clicked();
    void on_btnUserLogout_clicked();

    // Logout Page
    void on_btnLogoutBacktologin_clicked();
    void on_btnDbloginLogin_clicked();

    void on_tabStudent_tabBarClicked(int index);

    void on_btnLogOut_clicked();

    void on_tableRegister_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Database *database;
    Student *student = NULL;
    Faculty *faculty = NULL;
};

#endif // MAINWINDOW_H
