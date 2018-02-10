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
        layoutWidget->setGeometry(QRect(180, 50, 192, 100));
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
        btnConnectDatabase->setGeometry(QRect(200, 180, 141, 23));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
