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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *btnPage1Next;
    QLabel *label_2;
    QWidget *page_2;
    QPushButton *btnPage2Home;
    QPushButton *btnPage2Next;
    QLabel *label_3;
    QWidget *page_3;
    QPushButton *btnPage3Home;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(208, 173);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        btnPage1Next = new QPushButton(page);
        btnPage1Next->setObjectName(QStringLiteral("btnPage1Next"));
        btnPage1Next->setGeometry(QRect(20, 30, 75, 23));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 40, 47, 13));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        btnPage2Home = new QPushButton(page_2);
        btnPage2Home->setObjectName(QStringLiteral("btnPage2Home"));
        btnPage2Home->setGeometry(QRect(20, 30, 75, 23));
        btnPage2Next = new QPushButton(page_2);
        btnPage2Next->setObjectName(QStringLiteral("btnPage2Next"));
        btnPage2Next->setGeometry(QRect(30, 70, 75, 23));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 50, 47, 13));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        btnPage3Home = new QPushButton(page_3);
        btnPage3Home->setObjectName(QStringLiteral("btnPage3Home"));
        btnPage3Home->setGeometry(QRect(20, 20, 75, 23));
        label = new QLabel(page_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 70, 47, 13));
        stackedWidget->addWidget(page_3);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 208, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btnPage1Next->setText(QApplication::translate("MainWindow", "next", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Page 1", Q_NULLPTR));
        btnPage2Home->setText(QApplication::translate("MainWindow", "Home", Q_NULLPTR));
        btnPage2Next->setText(QApplication::translate("MainWindow", "next", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "page 2", Q_NULLPTR));
        btnPage3Home->setText(QApplication::translate("MainWindow", "Home", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Page3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
