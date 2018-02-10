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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *loLogin;
    QLabel *lblLogIn;
    QHBoxLayout *loUsername;
    QLabel *lblUserName;
    QLineEdit *inputUsername;
    QHBoxLayout *loPassword;
    QLabel *lblPassword;
    QLineEdit *inputPassword;
    QPushButton *btnLogin;
    QPushButton *btnConnectDatabase;
    QPushButton *pushButton;
    QWidget *layoutWidget_2;
    QVBoxLayout *loLogin_2;
    QLabel *lblLogIn_2;
    QHBoxLayout *loUsername_2;
    QLabel *lblUserName_2;
    QLineEdit *inputUsername_2;
    QHBoxLayout *loPassword_2;
    QLabel *lblPassword_2;
    QLineEdit *inputPassword_2;
    QPushButton *btnLogin_2;
    QWidget *layoutWidget_3;
    QVBoxLayout *loLogin_3;
    QLabel *lblLogIn_3;
    QHBoxLayout *loUsername_3;
    QLabel *lblUserName_3;
    QLineEdit *inputUsername_3;
    QHBoxLayout *loPassword_3;
    QLabel *lblPassword_3;
    QLineEdit *inputPassword_3;
    QPushButton *btnLogin_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 192, 100));
        loLogin = new QVBoxLayout(layoutWidget);
        loLogin->setSpacing(6);
        loLogin->setContentsMargins(11, 11, 11, 11);
        loLogin->setObjectName(QStringLiteral("loLogin"));
        loLogin->setContentsMargins(0, 0, 0, 0);
        lblLogIn = new QLabel(layoutWidget);
        lblLogIn->setObjectName(QStringLiteral("lblLogIn"));

        loLogin->addWidget(lblLogIn);

        loUsername = new QHBoxLayout();
        loUsername->setSpacing(6);
        loUsername->setObjectName(QStringLiteral("loUsername"));
        lblUserName = new QLabel(layoutWidget);
        lblUserName->setObjectName(QStringLiteral("lblUserName"));

        loUsername->addWidget(lblUserName);

        inputUsername = new QLineEdit(layoutWidget);
        inputUsername->setObjectName(QStringLiteral("inputUsername"));

        loUsername->addWidget(inputUsername);


        loLogin->addLayout(loUsername);

        loPassword = new QHBoxLayout();
        loPassword->setSpacing(6);
        loPassword->setObjectName(QStringLiteral("loPassword"));
        lblPassword = new QLabel(layoutWidget);
        lblPassword->setObjectName(QStringLiteral("lblPassword"));

        loPassword->addWidget(lblPassword);

        inputPassword = new QLineEdit(layoutWidget);
        inputPassword->setObjectName(QStringLiteral("inputPassword"));

        loPassword->addWidget(inputPassword);


        loLogin->addLayout(loPassword);

        btnLogin = new QPushButton(layoutWidget);
        btnLogin->setObjectName(QStringLiteral("btnLogin"));

        loLogin->addWidget(btnLogin);

        btnConnectDatabase = new QPushButton(centralWidget);
        btnConnectDatabase->setObjectName(QStringLiteral("btnConnectDatabase"));
        btnConnectDatabase->setGeometry(QRect(230, 80, 141, 23));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 140, 121, 23));
        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(110, 160, 192, 100));
        loLogin_2 = new QVBoxLayout(layoutWidget_2);
        loLogin_2->setSpacing(6);
        loLogin_2->setContentsMargins(11, 11, 11, 11);
        loLogin_2->setObjectName(QStringLiteral("loLogin_2"));
        loLogin_2->setContentsMargins(0, 0, 0, 0);
        lblLogIn_2 = new QLabel(layoutWidget_2);
        lblLogIn_2->setObjectName(QStringLiteral("lblLogIn_2"));

        loLogin_2->addWidget(lblLogIn_2);

        loUsername_2 = new QHBoxLayout();
        loUsername_2->setSpacing(6);
        loUsername_2->setObjectName(QStringLiteral("loUsername_2"));
        lblUserName_2 = new QLabel(layoutWidget_2);
        lblUserName_2->setObjectName(QStringLiteral("lblUserName_2"));

        loUsername_2->addWidget(lblUserName_2);

        inputUsername_2 = new QLineEdit(layoutWidget_2);
        inputUsername_2->setObjectName(QStringLiteral("inputUsername_2"));

        loUsername_2->addWidget(inputUsername_2);


        loLogin_2->addLayout(loUsername_2);

        loPassword_2 = new QHBoxLayout();
        loPassword_2->setSpacing(6);
        loPassword_2->setObjectName(QStringLiteral("loPassword_2"));
        lblPassword_2 = new QLabel(layoutWidget_2);
        lblPassword_2->setObjectName(QStringLiteral("lblPassword_2"));

        loPassword_2->addWidget(lblPassword_2);

        inputPassword_2 = new QLineEdit(layoutWidget_2);
        inputPassword_2->setObjectName(QStringLiteral("inputPassword_2"));

        loPassword_2->addWidget(inputPassword_2);


        loLogin_2->addLayout(loPassword_2);

        btnLogin_2 = new QPushButton(layoutWidget_2);
        btnLogin_2->setObjectName(QStringLiteral("btnLogin_2"));

        loLogin_2->addWidget(btnLogin_2);

        layoutWidget_3 = new QWidget(centralWidget);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(280, 210, 192, 100));
        loLogin_3 = new QVBoxLayout(layoutWidget_3);
        loLogin_3->setSpacing(6);
        loLogin_3->setContentsMargins(11, 11, 11, 11);
        loLogin_3->setObjectName(QStringLiteral("loLogin_3"));
        loLogin_3->setContentsMargins(0, 0, 0, 0);
        lblLogIn_3 = new QLabel(layoutWidget_3);
        lblLogIn_3->setObjectName(QStringLiteral("lblLogIn_3"));

        loLogin_3->addWidget(lblLogIn_3);

        loUsername_3 = new QHBoxLayout();
        loUsername_3->setSpacing(6);
        loUsername_3->setObjectName(QStringLiteral("loUsername_3"));
        lblUserName_3 = new QLabel(layoutWidget_3);
        lblUserName_3->setObjectName(QStringLiteral("lblUserName_3"));

        loUsername_3->addWidget(lblUserName_3);

        inputUsername_3 = new QLineEdit(layoutWidget_3);
        inputUsername_3->setObjectName(QStringLiteral("inputUsername_3"));

        loUsername_3->addWidget(inputUsername_3);


        loLogin_3->addLayout(loUsername_3);

        loPassword_3 = new QHBoxLayout();
        loPassword_3->setSpacing(6);
        loPassword_3->setObjectName(QStringLiteral("loPassword_3"));
        lblPassword_3 = new QLabel(layoutWidget_3);
        lblPassword_3->setObjectName(QStringLiteral("lblPassword_3"));

        loPassword_3->addWidget(lblPassword_3);

        inputPassword_3 = new QLineEdit(layoutWidget_3);
        inputPassword_3->setObjectName(QStringLiteral("inputPassword_3"));

        loPassword_3->addWidget(inputPassword_3);


        loLogin_3->addLayout(loPassword_3);

        btnLogin_3 = new QPushButton(layoutWidget_3);
        btnLogin_3->setObjectName(QStringLiteral("btnLogin_3"));

        loLogin_3->addWidget(btnLogin_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        lblLogIn->setText(QApplication::translate("MainWindow", "Log In", Q_NULLPTR));
        lblUserName->setText(QApplication::translate("MainWindow", "UserName", Q_NULLPTR));
        lblPassword->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        btnLogin->setText(QApplication::translate("MainWindow", "Log In", Q_NULLPTR));
        btnConnectDatabase->setText(QApplication::translate("MainWindow", "Connect Database", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Init Database", Q_NULLPTR));
        lblLogIn_2->setText(QApplication::translate("MainWindow", "Log In", Q_NULLPTR));
        lblUserName_2->setText(QApplication::translate("MainWindow", "UserName", Q_NULLPTR));
        lblPassword_2->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        btnLogin_2->setText(QApplication::translate("MainWindow", "Log In", Q_NULLPTR));
        lblLogIn_3->setText(QApplication::translate("MainWindow", "Log In", Q_NULLPTR));
        lblUserName_3->setText(QApplication::translate("MainWindow", "UserName", Q_NULLPTR));
        lblPassword_3->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        btnLogin_3->setText(QApplication::translate("MainWindow", "Log In", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
