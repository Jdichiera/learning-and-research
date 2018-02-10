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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widgetLogin;
    QVBoxLayout *loLogin;
    QLabel *lblLogIn;
    QHBoxLayout *loUsername;
    QLabel *lblUserName;
    QLineEdit *inputUsername;
    QHBoxLayout *loPassword;
    QLabel *lblPassword;
    QLineEdit *inputPassword;
    QPushButton *btnLogin;
    QWidget *widgetApplication;
    QVBoxLayout *loApplication;
    QTextBrowser *textUser;
    QTabWidget *tabUser;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *tab_3;
    QPushButton *btnLogout;
    QWidget *widgetDatabase;
    QPushButton *btnDatabaseInit;
    QTextBrowser *textDatabase;
    QPushButton *btnLogout_2;
    QPushButton *btnInitializeDatabase;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(949, 647);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widgetLogin = new QWidget(centralWidget);
        widgetLogin->setObjectName(QStringLiteral("widgetLogin"));
        widgetLogin->setGeometry(QRect(50, 30, 281, 171));
        loLogin = new QVBoxLayout(widgetLogin);
        loLogin->setSpacing(6);
        loLogin->setContentsMargins(11, 11, 11, 11);
        loLogin->setObjectName(QStringLiteral("loLogin"));
        lblLogIn = new QLabel(widgetLogin);
        lblLogIn->setObjectName(QStringLiteral("lblLogIn"));

        loLogin->addWidget(lblLogIn);

        loUsername = new QHBoxLayout();
        loUsername->setSpacing(6);
        loUsername->setObjectName(QStringLiteral("loUsername"));
        lblUserName = new QLabel(widgetLogin);
        lblUserName->setObjectName(QStringLiteral("lblUserName"));

        loUsername->addWidget(lblUserName);

        inputUsername = new QLineEdit(widgetLogin);
        inputUsername->setObjectName(QStringLiteral("inputUsername"));

        loUsername->addWidget(inputUsername);


        loLogin->addLayout(loUsername);

        loPassword = new QHBoxLayout();
        loPassword->setSpacing(6);
        loPassword->setObjectName(QStringLiteral("loPassword"));
        lblPassword = new QLabel(widgetLogin);
        lblPassword->setObjectName(QStringLiteral("lblPassword"));

        loPassword->addWidget(lblPassword);

        inputPassword = new QLineEdit(widgetLogin);
        inputPassword->setObjectName(QStringLiteral("inputPassword"));

        loPassword->addWidget(inputPassword);


        loLogin->addLayout(loPassword);

        btnLogin = new QPushButton(widgetLogin);
        btnLogin->setObjectName(QStringLiteral("btnLogin"));

        loLogin->addWidget(btnLogin);

        widgetApplication = new QWidget(centralWidget);
        widgetApplication->setObjectName(QStringLiteral("widgetApplication"));
        widgetApplication->setGeometry(QRect(10, 220, 601, 371));
        loApplication = new QVBoxLayout(widgetApplication);
        loApplication->setSpacing(6);
        loApplication->setContentsMargins(11, 11, 11, 11);
        loApplication->setObjectName(QStringLiteral("loApplication"));
        textUser = new QTextBrowser(widgetApplication);
        textUser->setObjectName(QStringLiteral("textUser"));

        loApplication->addWidget(textUser);

        tabUser = new QTabWidget(widgetApplication);
        tabUser->setObjectName(QStringLiteral("tabUser"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabUser->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabUser->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabUser->addTab(tab_3, QString());

        loApplication->addWidget(tabUser);

        btnLogout = new QPushButton(widgetApplication);
        btnLogout->setObjectName(QStringLiteral("btnLogout"));

        loApplication->addWidget(btnLogout);

        widgetDatabase = new QWidget(centralWidget);
        widgetDatabase->setObjectName(QStringLiteral("widgetDatabase"));
        widgetDatabase->setGeometry(QRect(400, 270, 341, 261));
        btnDatabaseInit = new QPushButton(widgetDatabase);
        btnDatabaseInit->setObjectName(QStringLiteral("btnDatabaseInit"));
        btnDatabaseInit->setGeometry(QRect(90, 170, 161, 23));
        textDatabase = new QTextBrowser(widgetDatabase);
        textDatabase->setObjectName(QStringLiteral("textDatabase"));
        textDatabase->setGeometry(QRect(10, 0, 321, 121));
        btnLogout_2 = new QPushButton(widgetDatabase);
        btnLogout_2->setObjectName(QStringLiteral("btnLogout_2"));
        btnLogout_2->setGeometry(QRect(130, 210, 81, 23));
        btnInitializeDatabase = new QPushButton(centralWidget);
        btnInitializeDatabase->setObjectName(QStringLiteral("btnInitializeDatabase"));
        btnInitializeDatabase->setGeometry(QRect(410, 80, 101, 23));
        MainWindow->setCentralWidget(centralWidget);
        widgetApplication->raise();
        widgetLogin->raise();
        widgetDatabase->raise();
        btnInitializeDatabase->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 949, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabUser->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        lblLogIn->setText(QApplication::translate("MainWindow", "Log In", Q_NULLPTR));
        lblUserName->setText(QApplication::translate("MainWindow", "UserName", Q_NULLPTR));
        lblPassword->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        btnLogin->setText(QApplication::translate("MainWindow", "Log In", Q_NULLPTR));
        tabUser->setTabText(tabUser->indexOf(tab), QApplication::translate("MainWindow", "Current Registration", Q_NULLPTR));
        tabUser->setTabText(tabUser->indexOf(tab_2), QApplication::translate("MainWindow", "Register for Classes", Q_NULLPTR));
        tabUser->setTabText(tabUser->indexOf(tab_3), QApplication::translate("MainWindow", "Course List", Q_NULLPTR));
        btnLogout->setText(QApplication::translate("MainWindow", "Log Out", Q_NULLPTR));
        btnDatabaseInit->setText(QApplication::translate("MainWindow", "Initialize Database", Q_NULLPTR));
        btnLogout_2->setText(QApplication::translate("MainWindow", "Log Out", Q_NULLPTR));
        btnInitializeDatabase->setText(QApplication::translate("MainWindow", "Try Database", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
