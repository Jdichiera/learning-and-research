/********************************************************************************
** Form generated from reading UI file 'mainview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEW_H
#define UI_MAINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainView
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStartServer;
    QPushButton *btnStopServer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainView)
    {
        if (MainView->objectName().isEmpty())
            MainView->setObjectName(QStringLiteral("MainView"));
        MainView->resize(265, 220);
        centralWidget = new QWidget(MainView);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnStartServer = new QPushButton(centralWidget);
        btnStartServer->setObjectName(QStringLiteral("btnStartServer"));

        horizontalLayout->addWidget(btnStartServer);

        btnStopServer = new QPushButton(centralWidget);
        btnStopServer->setObjectName(QStringLiteral("btnStopServer"));

        horizontalLayout->addWidget(btnStopServer);

        MainView->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainView);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 265, 21));
        MainView->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainView);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainView->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainView);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainView->setStatusBar(statusBar);

        retranslateUi(MainView);

        QMetaObject::connectSlotsByName(MainView);
    } // setupUi

    void retranslateUi(QMainWindow *MainView)
    {
        MainView->setWindowTitle(QApplication::translate("MainView", "MainView", Q_NULLPTR));
        btnStartServer->setText(QApplication::translate("MainView", "Start Server", Q_NULLPTR));
        btnStopServer->setText(QApplication::translate("MainView", "Stop Server", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainView: public Ui_MainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H
