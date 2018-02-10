/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *pageLogin;
    QWidget *layoutWidget;
    QVBoxLayout *loLogin;
    QLabel *labelStudentLogin;
    QHBoxLayout *horizontalLayout;
    QLabel *lblStudentUserName;
    QLineEdit *inputStudentLoginUsername;
    QHBoxLayout *loLoginPassword;
    QLabel *lblStudentPassword;
    QLineEdit *inputStudentLoginPassword;
    QPushButton *btnLogin;
    QLabel *labelStudentLoginBadpass;
    QWidget *pageDbLogin;
    QWidget *layoutWidget1;
    QVBoxLayout *loDbLogin;
    QLabel *labelDatabaseLoginTitle;
    QHBoxLayout *loDbLoginUsername;
    QLabel *lblDbloginUserName;
    QLineEdit *inputDbloginUsername;
    QHBoxLayout *loDbLoginPassword;
    QLabel *lblDbloginPassword;
    QLineEdit *inputDbloginPassword;
    QPushButton *btnDbloginLogin;
    QPushButton *btnDbloginBack;
    QPushButton *btnDbLoginGotoFacultyLogin;
    QWidget *pageFacultyLogin;
    QWidget *layoutWidget_2;
    QVBoxLayout *loFacultyLogin;
    QLabel *labelStudentLogin_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblFacultyName;
    QLineEdit *inputFacultyUsername;
    QHBoxLayout *loLoginPassword_2;
    QLabel *lblFacultyPassword;
    QLineEdit *inputFacultyPassword;
    QPushButton *btnFacultyLogin;
    QLabel *labelFacultyLoginBadpass;
    QPushButton *btnFacultyLoginGotoStudentLogin;
    QPushButton *btnFacultyLoginGotoDBLogin;
    QWidget *pageDbAdmin;
    QWidget *widgetDatabase;
    QPushButton *btnDbAdminDropTable;
    QPushButton *btnDbAdminLogout;
    QPushButton *btnDbAdminAddTables;
    QPushButton *btnDbAdminSeedTables;
    QTextEdit *textDbAdminConsole;
    QWidget *pageStudent;
    QTabWidget *tabStudent;
    QWidget *tabRegistration;
    QTableWidget *tableCurrentRegistration;
    QWidget *tabRegister;
    QTableWidget *tableRegister;
    QWidget *tabCourses;
    QTableWidget *tableCourseHistory;
    QWidget *layoutWidget2;
    QVBoxLayout *loStudentInfo;
    QHBoxLayout *loStudentId;
    QLabel *labelStudentId;
    QLineEdit *inputStudentId;
    QHBoxLayout *loStudentFirstName;
    QLabel *labelStudentFirstName;
    QLineEdit *inputStudentFirstName;
    QHBoxLayout *loStudentLastName;
    QLabel *labelStudentLastName;
    QLineEdit *inputStudentLastName;
    QHBoxLayout *loStudentEmail;
    QLabel *labelStudentEmail;
    QLineEdit *inputStudentEmail;
    QHBoxLayout *loStudentGPA;
    QLabel *labelStudentGPA;
    QLineEdit *inputStudentGPA;
    QPushButton *btnLogOut;
    QWidget *pageFaculty;
    QPushButton *btnFacultyLogout;
    QWidget *layoutWidget_3;
    QVBoxLayout *loFacultyInfo;
    QHBoxLayout *loFacultyId;
    QLabel *labelFacultyId;
    QLineEdit *inputFacultyId;
    QHBoxLayout *loFacultyFirstName;
    QLabel *labelFacultyFirstName;
    QLineEdit *inputFacultyFirstName;
    QHBoxLayout *loFacultyLastName;
    QLabel *labelFacultyLastName;
    QLineEdit *inputFacultyLastName;
    QHBoxLayout *loFacultyEmail;
    QLabel *labelFacultyEmail;
    QLineEdit *inputFacultyEmail;
    QTabWidget *tabFaculty;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;
    QWidget *pageLogOut;
    QTextEdit *textLogoutConsole;
    QPushButton *btnLogoutBacktologin;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1055, 648);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 1031, 581));
        pageLogin = new QWidget();
        pageLogin->setObjectName(QStringLiteral("pageLogin"));
        layoutWidget = new QWidget(pageLogin);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 140, 231, 191));
        loLogin = new QVBoxLayout(layoutWidget);
        loLogin->setSpacing(6);
        loLogin->setContentsMargins(11, 11, 11, 11);
        loLogin->setObjectName(QStringLiteral("loLogin"));
        loLogin->setContentsMargins(0, 0, 0, 0);
        labelStudentLogin = new QLabel(layoutWidget);
        labelStudentLogin->setObjectName(QStringLiteral("labelStudentLogin"));

        loLogin->addWidget(labelStudentLogin);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblStudentUserName = new QLabel(layoutWidget);
        lblStudentUserName->setObjectName(QStringLiteral("lblStudentUserName"));

        horizontalLayout->addWidget(lblStudentUserName);

        inputStudentLoginUsername = new QLineEdit(layoutWidget);
        inputStudentLoginUsername->setObjectName(QStringLiteral("inputStudentLoginUsername"));

        horizontalLayout->addWidget(inputStudentLoginUsername);


        loLogin->addLayout(horizontalLayout);

        loLoginPassword = new QHBoxLayout();
        loLoginPassword->setSpacing(6);
        loLoginPassword->setObjectName(QStringLiteral("loLoginPassword"));
        lblStudentPassword = new QLabel(layoutWidget);
        lblStudentPassword->setObjectName(QStringLiteral("lblStudentPassword"));

        loLoginPassword->addWidget(lblStudentPassword);

        inputStudentLoginPassword = new QLineEdit(layoutWidget);
        inputStudentLoginPassword->setObjectName(QStringLiteral("inputStudentLoginPassword"));

        loLoginPassword->addWidget(inputStudentLoginPassword);


        loLogin->addLayout(loLoginPassword);

        btnLogin = new QPushButton(layoutWidget);
        btnLogin->setObjectName(QStringLiteral("btnLogin"));

        loLogin->addWidget(btnLogin);

        labelStudentLoginBadpass = new QLabel(layoutWidget);
        labelStudentLoginBadpass->setObjectName(QStringLiteral("labelStudentLoginBadpass"));

        loLogin->addWidget(labelStudentLoginBadpass);

        stackedWidget->addWidget(pageLogin);
        pageDbLogin = new QWidget();
        pageDbLogin->setObjectName(QStringLiteral("pageDbLogin"));
        layoutWidget1 = new QWidget(pageDbLogin);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 70, 281, 141));
        loDbLogin = new QVBoxLayout(layoutWidget1);
        loDbLogin->setSpacing(6);
        loDbLogin->setContentsMargins(11, 11, 11, 11);
        loDbLogin->setObjectName(QStringLiteral("loDbLogin"));
        loDbLogin->setContentsMargins(0, 0, 0, 0);
        labelDatabaseLoginTitle = new QLabel(layoutWidget1);
        labelDatabaseLoginTitle->setObjectName(QStringLiteral("labelDatabaseLoginTitle"));

        loDbLogin->addWidget(labelDatabaseLoginTitle);

        loDbLoginUsername = new QHBoxLayout();
        loDbLoginUsername->setSpacing(6);
        loDbLoginUsername->setObjectName(QStringLiteral("loDbLoginUsername"));
        lblDbloginUserName = new QLabel(layoutWidget1);
        lblDbloginUserName->setObjectName(QStringLiteral("lblDbloginUserName"));

        loDbLoginUsername->addWidget(lblDbloginUserName);

        inputDbloginUsername = new QLineEdit(layoutWidget1);
        inputDbloginUsername->setObjectName(QStringLiteral("inputDbloginUsername"));

        loDbLoginUsername->addWidget(inputDbloginUsername);


        loDbLogin->addLayout(loDbLoginUsername);

        loDbLoginPassword = new QHBoxLayout();
        loDbLoginPassword->setSpacing(6);
        loDbLoginPassword->setObjectName(QStringLiteral("loDbLoginPassword"));
        lblDbloginPassword = new QLabel(layoutWidget1);
        lblDbloginPassword->setObjectName(QStringLiteral("lblDbloginPassword"));

        loDbLoginPassword->addWidget(lblDbloginPassword);

        inputDbloginPassword = new QLineEdit(layoutWidget1);
        inputDbloginPassword->setObjectName(QStringLiteral("inputDbloginPassword"));

        loDbLoginPassword->addWidget(inputDbloginPassword);


        loDbLogin->addLayout(loDbLoginPassword);

        btnDbloginLogin = new QPushButton(layoutWidget1);
        btnDbloginLogin->setObjectName(QStringLiteral("btnDbloginLogin"));

        loDbLogin->addWidget(btnDbloginLogin);

        btnDbloginBack = new QPushButton(pageDbLogin);
        btnDbloginBack->setObjectName(QStringLiteral("btnDbloginBack"));
        btnDbloginBack->setGeometry(QRect(230, 220, 101, 23));
        btnDbLoginGotoFacultyLogin = new QPushButton(pageDbLogin);
        btnDbLoginGotoFacultyLogin->setObjectName(QStringLiteral("btnDbLoginGotoFacultyLogin"));
        btnDbLoginGotoFacultyLogin->setGeometry(QRect(120, 220, 101, 23));
        stackedWidget->addWidget(pageDbLogin);
        pageFacultyLogin = new QWidget();
        pageFacultyLogin->setObjectName(QStringLiteral("pageFacultyLogin"));
        layoutWidget_2 = new QWidget(pageFacultyLogin);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(120, 70, 231, 191));
        loFacultyLogin = new QVBoxLayout(layoutWidget_2);
        loFacultyLogin->setSpacing(6);
        loFacultyLogin->setContentsMargins(11, 11, 11, 11);
        loFacultyLogin->setObjectName(QStringLiteral("loFacultyLogin"));
        loFacultyLogin->setContentsMargins(0, 0, 0, 0);
        labelStudentLogin_2 = new QLabel(layoutWidget_2);
        labelStudentLogin_2->setObjectName(QStringLiteral("labelStudentLogin_2"));

        loFacultyLogin->addWidget(labelStudentLogin_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lblFacultyName = new QLabel(layoutWidget_2);
        lblFacultyName->setObjectName(QStringLiteral("lblFacultyName"));

        horizontalLayout_2->addWidget(lblFacultyName);

        inputFacultyUsername = new QLineEdit(layoutWidget_2);
        inputFacultyUsername->setObjectName(QStringLiteral("inputFacultyUsername"));

        horizontalLayout_2->addWidget(inputFacultyUsername);


        loFacultyLogin->addLayout(horizontalLayout_2);

        loLoginPassword_2 = new QHBoxLayout();
        loLoginPassword_2->setSpacing(6);
        loLoginPassword_2->setObjectName(QStringLiteral("loLoginPassword_2"));
        lblFacultyPassword = new QLabel(layoutWidget_2);
        lblFacultyPassword->setObjectName(QStringLiteral("lblFacultyPassword"));

        loLoginPassword_2->addWidget(lblFacultyPassword);

        inputFacultyPassword = new QLineEdit(layoutWidget_2);
        inputFacultyPassword->setObjectName(QStringLiteral("inputFacultyPassword"));

        loLoginPassword_2->addWidget(inputFacultyPassword);


        loFacultyLogin->addLayout(loLoginPassword_2);

        btnFacultyLogin = new QPushButton(layoutWidget_2);
        btnFacultyLogin->setObjectName(QStringLiteral("btnFacultyLogin"));

        loFacultyLogin->addWidget(btnFacultyLogin);

        labelFacultyLoginBadpass = new QLabel(layoutWidget_2);
        labelFacultyLoginBadpass->setObjectName(QStringLiteral("labelFacultyLoginBadpass"));

        loFacultyLogin->addWidget(labelFacultyLoginBadpass);

        btnFacultyLoginGotoStudentLogin = new QPushButton(pageFacultyLogin);
        btnFacultyLoginGotoStudentLogin->setObjectName(QStringLiteral("btnFacultyLoginGotoStudentLogin"));
        btnFacultyLoginGotoStudentLogin->setGeometry(QRect(250, 270, 101, 23));
        btnFacultyLoginGotoDBLogin = new QPushButton(pageFacultyLogin);
        btnFacultyLoginGotoDBLogin->setObjectName(QStringLiteral("btnFacultyLoginGotoDBLogin"));
        btnFacultyLoginGotoDBLogin->setGeometry(QRect(130, 270, 111, 23));
        stackedWidget->addWidget(pageFacultyLogin);
        pageDbAdmin = new QWidget();
        pageDbAdmin->setObjectName(QStringLiteral("pageDbAdmin"));
        widgetDatabase = new QWidget(pageDbAdmin);
        widgetDatabase->setObjectName(QStringLiteral("widgetDatabase"));
        widgetDatabase->setGeometry(QRect(0, 0, 771, 521));
        btnDbAdminDropTable = new QPushButton(widgetDatabase);
        btnDbAdminDropTable->setObjectName(QStringLiteral("btnDbAdminDropTable"));
        btnDbAdminDropTable->setGeometry(QRect(290, 340, 161, 23));
        btnDbAdminLogout = new QPushButton(widgetDatabase);
        btnDbAdminLogout->setObjectName(QStringLiteral("btnDbAdminLogout"));
        btnDbAdminLogout->setGeometry(QRect(330, 430, 81, 23));
        btnDbAdminAddTables = new QPushButton(widgetDatabase);
        btnDbAdminAddTables->setObjectName(QStringLiteral("btnDbAdminAddTables"));
        btnDbAdminAddTables->setGeometry(QRect(290, 370, 161, 23));
        btnDbAdminSeedTables = new QPushButton(widgetDatabase);
        btnDbAdminSeedTables->setObjectName(QStringLiteral("btnDbAdminSeedTables"));
        btnDbAdminSeedTables->setGeometry(QRect(290, 400, 161, 23));
        textDbAdminConsole = new QTextEdit(widgetDatabase);
        textDbAdminConsole->setObjectName(QStringLiteral("textDbAdminConsole"));
        textDbAdminConsole->setGeometry(QRect(13, 10, 751, 321));
        textDbAdminConsole->setReadOnly(true);
        stackedWidget->addWidget(pageDbAdmin);
        pageStudent = new QWidget();
        pageStudent->setObjectName(QStringLiteral("pageStudent"));
        tabStudent = new QTabWidget(pageStudent);
        tabStudent->setObjectName(QStringLiteral("tabStudent"));
        tabStudent->setGeometry(QRect(0, 210, 1031, 321));
        tabRegistration = new QWidget();
        tabRegistration->setObjectName(QStringLiteral("tabRegistration"));
        tableCurrentRegistration = new QTableWidget(tabRegistration);
        if (tableCurrentRegistration->columnCount() < 7)
            tableCurrentRegistration->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableCurrentRegistration->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableCurrentRegistration->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableCurrentRegistration->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableCurrentRegistration->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableCurrentRegistration->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableCurrentRegistration->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableCurrentRegistration->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableCurrentRegistration->setObjectName(QStringLiteral("tableCurrentRegistration"));
        tableCurrentRegistration->setGeometry(QRect(10, 10, 1001, 281));
        tabStudent->addTab(tabRegistration, QString());
        tabRegister = new QWidget();
        tabRegister->setObjectName(QStringLiteral("tabRegister"));
        tableRegister = new QTableWidget(tabRegister);
        if (tableRegister->columnCount() < 6)
            tableRegister->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableRegister->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableRegister->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableRegister->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableRegister->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableRegister->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableRegister->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        tableRegister->setObjectName(QStringLiteral("tableRegister"));
        tableRegister->setGeometry(QRect(10, 10, 1001, 281));
        tabStudent->addTab(tabRegister, QString());
        tabCourses = new QWidget();
        tabCourses->setObjectName(QStringLiteral("tabCourses"));
        tableCourseHistory = new QTableWidget(tabCourses);
        if (tableCourseHistory->columnCount() < 9)
            tableCourseHistory->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableCourseHistory->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableCourseHistory->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableCourseHistory->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableCourseHistory->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableCourseHistory->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableCourseHistory->setHorizontalHeaderItem(5, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableCourseHistory->setHorizontalHeaderItem(6, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableCourseHistory->setHorizontalHeaderItem(7, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableCourseHistory->setHorizontalHeaderItem(8, __qtablewidgetitem21);
        tableCourseHistory->setObjectName(QStringLiteral("tableCourseHistory"));
        tableCourseHistory->setGeometry(QRect(10, 10, 1011, 281));
        tabStudent->addTab(tabCourses, QString());
        layoutWidget2 = new QWidget(pageStudent);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 0, 371, 194));
        loStudentInfo = new QVBoxLayout(layoutWidget2);
        loStudentInfo->setSpacing(6);
        loStudentInfo->setContentsMargins(11, 11, 11, 11);
        loStudentInfo->setObjectName(QStringLiteral("loStudentInfo"));
        loStudentInfo->setContentsMargins(0, 0, 0, 0);
        loStudentId = new QHBoxLayout();
        loStudentId->setSpacing(6);
        loStudentId->setObjectName(QStringLiteral("loStudentId"));
        labelStudentId = new QLabel(layoutWidget2);
        labelStudentId->setObjectName(QStringLiteral("labelStudentId"));
        labelStudentId->setMinimumSize(QSize(107, 0));
        labelStudentId->setMargin(5);

        loStudentId->addWidget(labelStudentId);

        inputStudentId = new QLineEdit(layoutWidget2);
        inputStudentId->setObjectName(QStringLiteral("inputStudentId"));
        inputStudentId->setReadOnly(true);

        loStudentId->addWidget(inputStudentId);


        loStudentInfo->addLayout(loStudentId);

        loStudentFirstName = new QHBoxLayout();
        loStudentFirstName->setSpacing(6);
        loStudentFirstName->setObjectName(QStringLiteral("loStudentFirstName"));
        labelStudentFirstName = new QLabel(layoutWidget2);
        labelStudentFirstName->setObjectName(QStringLiteral("labelStudentFirstName"));
        labelStudentFirstName->setMinimumSize(QSize(107, 0));
        labelStudentFirstName->setMargin(5);

        loStudentFirstName->addWidget(labelStudentFirstName);

        inputStudentFirstName = new QLineEdit(layoutWidget2);
        inputStudentFirstName->setObjectName(QStringLiteral("inputStudentFirstName"));
        inputStudentFirstName->setReadOnly(true);

        loStudentFirstName->addWidget(inputStudentFirstName);


        loStudentInfo->addLayout(loStudentFirstName);

        loStudentLastName = new QHBoxLayout();
        loStudentLastName->setSpacing(6);
        loStudentLastName->setObjectName(QStringLiteral("loStudentLastName"));
        labelStudentLastName = new QLabel(layoutWidget2);
        labelStudentLastName->setObjectName(QStringLiteral("labelStudentLastName"));
        labelStudentLastName->setMinimumSize(QSize(107, 0));
        labelStudentLastName->setMargin(5);

        loStudentLastName->addWidget(labelStudentLastName);

        inputStudentLastName = new QLineEdit(layoutWidget2);
        inputStudentLastName->setObjectName(QStringLiteral("inputStudentLastName"));
        inputStudentLastName->setReadOnly(true);

        loStudentLastName->addWidget(inputStudentLastName);


        loStudentInfo->addLayout(loStudentLastName);

        loStudentEmail = new QHBoxLayout();
        loStudentEmail->setSpacing(6);
        loStudentEmail->setObjectName(QStringLiteral("loStudentEmail"));
        labelStudentEmail = new QLabel(layoutWidget2);
        labelStudentEmail->setObjectName(QStringLiteral("labelStudentEmail"));
        labelStudentEmail->setMinimumSize(QSize(107, 0));
        labelStudentEmail->setMargin(5);

        loStudentEmail->addWidget(labelStudentEmail);

        inputStudentEmail = new QLineEdit(layoutWidget2);
        inputStudentEmail->setObjectName(QStringLiteral("inputStudentEmail"));
        inputStudentEmail->setReadOnly(true);

        loStudentEmail->addWidget(inputStudentEmail);


        loStudentInfo->addLayout(loStudentEmail);

        loStudentGPA = new QHBoxLayout();
        loStudentGPA->setSpacing(6);
        loStudentGPA->setObjectName(QStringLiteral("loStudentGPA"));
        labelStudentGPA = new QLabel(layoutWidget2);
        labelStudentGPA->setObjectName(QStringLiteral("labelStudentGPA"));
        labelStudentGPA->setMinimumSize(QSize(107, 0));
        labelStudentGPA->setMargin(5);

        loStudentGPA->addWidget(labelStudentGPA);

        inputStudentGPA = new QLineEdit(layoutWidget2);
        inputStudentGPA->setObjectName(QStringLiteral("inputStudentGPA"));
        inputStudentGPA->setReadOnly(true);

        loStudentGPA->addWidget(inputStudentGPA);


        loStudentInfo->addLayout(loStudentGPA);

        btnLogOut = new QPushButton(pageStudent);
        btnLogOut->setObjectName(QStringLiteral("btnLogOut"));
        btnLogOut->setGeometry(QRect(940, 550, 75, 23));
        stackedWidget->addWidget(pageStudent);
        pageFaculty = new QWidget();
        pageFaculty->setObjectName(QStringLiteral("pageFaculty"));
        btnFacultyLogout = new QPushButton(pageFaculty);
        btnFacultyLogout->setObjectName(QStringLiteral("btnFacultyLogout"));
        btnFacultyLogout->setGeometry(QRect(60, 320, 291, 23));
        layoutWidget_3 = new QWidget(pageFaculty);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 20, 371, 194));
        loFacultyInfo = new QVBoxLayout(layoutWidget_3);
        loFacultyInfo->setSpacing(6);
        loFacultyInfo->setContentsMargins(11, 11, 11, 11);
        loFacultyInfo->setObjectName(QStringLiteral("loFacultyInfo"));
        loFacultyInfo->setContentsMargins(0, 0, 0, 0);
        loFacultyId = new QHBoxLayout();
        loFacultyId->setSpacing(6);
        loFacultyId->setObjectName(QStringLiteral("loFacultyId"));
        labelFacultyId = new QLabel(layoutWidget_3);
        labelFacultyId->setObjectName(QStringLiteral("labelFacultyId"));
        labelFacultyId->setMinimumSize(QSize(107, 0));
        labelFacultyId->setMargin(5);

        loFacultyId->addWidget(labelFacultyId);

        inputFacultyId = new QLineEdit(layoutWidget_3);
        inputFacultyId->setObjectName(QStringLiteral("inputFacultyId"));
        inputFacultyId->setReadOnly(true);

        loFacultyId->addWidget(inputFacultyId);


        loFacultyInfo->addLayout(loFacultyId);

        loFacultyFirstName = new QHBoxLayout();
        loFacultyFirstName->setSpacing(6);
        loFacultyFirstName->setObjectName(QStringLiteral("loFacultyFirstName"));
        labelFacultyFirstName = new QLabel(layoutWidget_3);
        labelFacultyFirstName->setObjectName(QStringLiteral("labelFacultyFirstName"));
        labelFacultyFirstName->setMinimumSize(QSize(107, 0));
        labelFacultyFirstName->setMargin(5);

        loFacultyFirstName->addWidget(labelFacultyFirstName);

        inputFacultyFirstName = new QLineEdit(layoutWidget_3);
        inputFacultyFirstName->setObjectName(QStringLiteral("inputFacultyFirstName"));
        inputFacultyFirstName->setReadOnly(true);

        loFacultyFirstName->addWidget(inputFacultyFirstName);


        loFacultyInfo->addLayout(loFacultyFirstName);

        loFacultyLastName = new QHBoxLayout();
        loFacultyLastName->setSpacing(6);
        loFacultyLastName->setObjectName(QStringLiteral("loFacultyLastName"));
        labelFacultyLastName = new QLabel(layoutWidget_3);
        labelFacultyLastName->setObjectName(QStringLiteral("labelFacultyLastName"));
        labelFacultyLastName->setMinimumSize(QSize(107, 0));
        labelFacultyLastName->setMargin(5);

        loFacultyLastName->addWidget(labelFacultyLastName);

        inputFacultyLastName = new QLineEdit(layoutWidget_3);
        inputFacultyLastName->setObjectName(QStringLiteral("inputFacultyLastName"));
        inputFacultyLastName->setReadOnly(true);

        loFacultyLastName->addWidget(inputFacultyLastName);


        loFacultyInfo->addLayout(loFacultyLastName);

        loFacultyEmail = new QHBoxLayout();
        loFacultyEmail->setSpacing(6);
        loFacultyEmail->setObjectName(QStringLiteral("loFacultyEmail"));
        labelFacultyEmail = new QLabel(layoutWidget_3);
        labelFacultyEmail->setObjectName(QStringLiteral("labelFacultyEmail"));
        labelFacultyEmail->setMinimumSize(QSize(107, 0));
        labelFacultyEmail->setMargin(5);

        loFacultyEmail->addWidget(labelFacultyEmail);

        inputFacultyEmail = new QLineEdit(layoutWidget_3);
        inputFacultyEmail->setObjectName(QStringLiteral("inputFacultyEmail"));
        inputFacultyEmail->setReadOnly(true);

        loFacultyEmail->addWidget(inputFacultyEmail);


        loFacultyInfo->addLayout(loFacultyEmail);

        tabFaculty = new QTabWidget(pageFaculty);
        tabFaculty->setObjectName(QStringLiteral("tabFaculty"));
        tabFaculty->setGeometry(QRect(30, 210, 371, 111));
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabFaculty->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabFaculty->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tabFaculty->addTab(tab_6, QString());
        stackedWidget->addWidget(pageFaculty);
        pageLogOut = new QWidget();
        pageLogOut->setObjectName(QStringLiteral("pageLogOut"));
        textLogoutConsole = new QTextEdit(pageLogOut);
        textLogoutConsole->setObjectName(QStringLiteral("textLogoutConsole"));
        textLogoutConsole->setGeometry(QRect(10, 0, 761, 321));
        btnLogoutBacktologin = new QPushButton(pageLogOut);
        btnLogoutBacktologin->setObjectName(QStringLiteral("btnLogoutBacktologin"));
        btnLogoutBacktologin->setGeometry(QRect(270, 340, 161, 23));
        stackedWidget->addWidget(pageLogOut);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1055, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);
        tabStudent->setCurrentIndex(0);
        tabFaculty->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        labelStudentLogin->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Login</span></p></body></html>", Q_NULLPTR));
        lblStudentUserName->setText(QApplication::translate("MainWindow", "UserName", Q_NULLPTR));
        lblStudentPassword->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        btnLogin->setText(QApplication::translate("MainWindow", "Log In", Q_NULLPTR));
        labelStudentLoginBadpass->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:7pt; font-weight:600;\">Incorrect Password </span></p><p align=\"center\"><span style=\" font-size:7pt; font-weight:600;\">Please try again</span></p></body></html>", Q_NULLPTR));
        labelDatabaseLoginTitle->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Database Login</span></p></body></html>", Q_NULLPTR));
        lblDbloginUserName->setText(QApplication::translate("MainWindow", "Database UserName", Q_NULLPTR));
        lblDbloginPassword->setText(QApplication::translate("MainWindow", "Database Password", Q_NULLPTR));
        btnDbloginLogin->setText(QApplication::translate("MainWindow", "Log Into Database", Q_NULLPTR));
        btnDbloginBack->setText(QApplication::translate("MainWindow", "Student Login", Q_NULLPTR));
        btnDbLoginGotoFacultyLogin->setText(QApplication::translate("MainWindow", "Faculty Login", Q_NULLPTR));
        labelStudentLogin_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Faculty Login</span></p></body></html>", Q_NULLPTR));
        lblFacultyName->setText(QApplication::translate("MainWindow", "UserName", Q_NULLPTR));
        lblFacultyPassword->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        btnFacultyLogin->setText(QApplication::translate("MainWindow", "Faculty Log In", Q_NULLPTR));
        labelFacultyLoginBadpass->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:7pt; font-weight:600;\">Incorrect Password </span></p><p align=\"center\"><span style=\" font-size:7pt; font-weight:600;\">Please try again</span></p></body></html>", Q_NULLPTR));
        btnFacultyLoginGotoStudentLogin->setText(QApplication::translate("MainWindow", "Student Login", Q_NULLPTR));
        btnFacultyLoginGotoDBLogin->setText(QApplication::translate("MainWindow", "Database Login", Q_NULLPTR));
        btnDbAdminDropTable->setText(QApplication::translate("MainWindow", "Drop All Tables", Q_NULLPTR));
        btnDbAdminLogout->setText(QApplication::translate("MainWindow", "Log Out", Q_NULLPTR));
        btnDbAdminAddTables->setText(QApplication::translate("MainWindow", "Add New Tables", Q_NULLPTR));
        btnDbAdminSeedTables->setText(QApplication::translate("MainWindow", "Seed Tables", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableCurrentRegistration->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Semester", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableCurrentRegistration->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Id", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableCurrentRegistration->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Course", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableCurrentRegistration->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableCurrentRegistration->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Registered", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableCurrentRegistration->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Credits", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableCurrentRegistration->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Grade", Q_NULLPTR));
        tabStudent->setTabText(tabStudent->indexOf(tabRegistration), QApplication::translate("MainWindow", "Current Registration", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableRegister->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Semester", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableRegister->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Id", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableRegister->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Course", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableRegister->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableRegister->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Credits", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableRegister->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Description", Q_NULLPTR));
        tabStudent->setTabText(tabStudent->indexOf(tabRegister), QApplication::translate("MainWindow", "Register for Classes", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableCourseHistory->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Semester", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableCourseHistory->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Id", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableCourseHistory->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "Course", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableCourseHistory->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableCourseHistory->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Status", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableCourseHistory->horizontalHeaderItem(5);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "Registered", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableCourseHistory->horizontalHeaderItem(6);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "Completed", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableCourseHistory->horizontalHeaderItem(7);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "Credits", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableCourseHistory->horizontalHeaderItem(8);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "Grade", Q_NULLPTR));
        tabStudent->setTabText(tabStudent->indexOf(tabCourses), QApplication::translate("MainWindow", "Course History", Q_NULLPTR));
        labelStudentId->setText(QApplication::translate("MainWindow", "Student ID: ", Q_NULLPTR));
        labelStudentFirstName->setText(QApplication::translate("MainWindow", "First Name: ", Q_NULLPTR));
        labelStudentLastName->setText(QApplication::translate("MainWindow", "Last Name: ", Q_NULLPTR));
        labelStudentEmail->setText(QApplication::translate("MainWindow", "Email Address: ", Q_NULLPTR));
        labelStudentGPA->setText(QApplication::translate("MainWindow", "GPA: ", Q_NULLPTR));
        btnLogOut->setText(QApplication::translate("MainWindow", "Log Out", Q_NULLPTR));
        btnFacultyLogout->setText(QApplication::translate("MainWindow", "Log Out", Q_NULLPTR));
        labelFacultyId->setText(QApplication::translate("MainWindow", "Faculty ID", Q_NULLPTR));
        labelFacultyFirstName->setText(QApplication::translate("MainWindow", "First Name: ", Q_NULLPTR));
        labelFacultyLastName->setText(QApplication::translate("MainWindow", "Last Name: ", Q_NULLPTR));
        labelFacultyEmail->setText(QApplication::translate("MainWindow", "Email Address: ", Q_NULLPTR));
        tabFaculty->setTabText(tabFaculty->indexOf(tab_4), QApplication::translate("MainWindow", "Students", Q_NULLPTR));
        tabFaculty->setTabText(tabFaculty->indexOf(tab_5), QApplication::translate("MainWindow", "Semesters", Q_NULLPTR));
        tabFaculty->setTabText(tabFaculty->indexOf(tab_6), QApplication::translate("MainWindow", "Course List", Q_NULLPTR));
        btnLogoutBacktologin->setText(QApplication::translate("MainWindow", "Back to login", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
