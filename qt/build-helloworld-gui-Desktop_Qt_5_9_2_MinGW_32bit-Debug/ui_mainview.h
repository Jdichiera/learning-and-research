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
    QPushButton *w_exitButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainView)
    {
        if (MainView->objectName().isEmpty())
            MainView->setObjectName(QStringLiteral("MainView"));
        MainView->resize(400, 300);
        centralWidget = new QWidget(MainView);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        w_exitButton = new QPushButton(centralWidget);
        w_exitButton->setObjectName(QStringLiteral("w_exitButton"));
        w_exitButton->setGeometry(QRect(140, 150, 75, 23));
        MainView->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainView);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
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
        w_exitButton->setText(QApplication::translate("MainView", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainView: public Ui_MainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H
