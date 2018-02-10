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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainView
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabMainView;
    QWidget *tabControl;
    QWidget *tabSetup;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *loSetupTab;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainView)
    {
        if (MainView->objectName().isEmpty())
            MainView->setObjectName(QStringLiteral("MainView"));
        MainView->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/root/Images/0.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainView->setWindowIcon(icon);
        centralWidget = new QWidget(MainView);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabMainView = new QTabWidget(centralWidget);
        tabMainView->setObjectName(QStringLiteral("tabMainView"));
        tabControl = new QWidget();
        tabControl->setObjectName(QStringLiteral("tabControl"));
        tabMainView->addTab(tabControl, QString());
        tabSetup = new QWidget();
        tabSetup->setObjectName(QStringLiteral("tabSetup"));
        verticalLayout_2 = new QVBoxLayout(tabSetup);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        loSetupTab = new QVBoxLayout();
        loSetupTab->setSpacing(6);
        loSetupTab->setObjectName(QStringLiteral("loSetupTab"));

        verticalLayout_2->addLayout(loSetupTab);

        tabMainView->addTab(tabSetup, QString());

        horizontalLayout->addWidget(tabMainView);

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

        tabMainView->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainView);
    } // setupUi

    void retranslateUi(QMainWindow *MainView)
    {
        MainView->setWindowTitle(QApplication::translate("MainView", "VirtualFrontPanel - Gating Controller", Q_NULLPTR));
        tabMainView->setTabText(tabMainView->indexOf(tabControl), QApplication::translate("MainView", "Control", Q_NULLPTR));
        tabMainView->setTabText(tabMainView->indexOf(tabSetup), QApplication::translate("MainView", "Setup", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainView: public Ui_MainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H
