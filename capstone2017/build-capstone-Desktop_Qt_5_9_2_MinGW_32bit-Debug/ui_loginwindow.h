/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

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

class Ui_LoginWindow
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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(364, 259);
        centralWidget = new QWidget(LoginWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 50, 192, 100));
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

        LoginWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LoginWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 364, 21));
        LoginWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LoginWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LoginWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LoginWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LoginWindow->setStatusBar(statusBar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "LoginWindow", Q_NULLPTR));
        lblLogIn->setText(QApplication::translate("LoginWindow", "Log In", Q_NULLPTR));
        lblUserName->setText(QApplication::translate("LoginWindow", "UserName", Q_NULLPTR));
        lblPassword->setText(QApplication::translate("LoginWindow", "Password", Q_NULLPTR));
        btnLogin->setText(QApplication::translate("LoginWindow", "Log In", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
