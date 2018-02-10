/********************************************************************************
** Form generated from reading UI file 'application.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATION_H
#define UI_APPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Application
{
public:
    QTabWidget *tabMainWindow;
    QWidget *tab;
    QWidget *tab_2;
    QTextBrowser *textUserInformation;

    void setupUi(QWidget *Application)
    {
        if (Application->objectName().isEmpty())
            Application->setObjectName(QStringLiteral("Application"));
        Application->resize(490, 413);
        tabMainWindow = new QTabWidget(Application);
        tabMainWindow->setObjectName(QStringLiteral("tabMainWindow"));
        tabMainWindow->setGeometry(QRect(10, 130, 471, 271));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabMainWindow->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabMainWindow->addTab(tab_2, QString());
        textUserInformation = new QTextBrowser(Application);
        textUserInformation->setObjectName(QStringLiteral("textUserInformation"));
        textUserInformation->setGeometry(QRect(10, 10, 471, 101));

        retranslateUi(Application);

        tabMainWindow->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Application);
    } // setupUi

    void retranslateUi(QWidget *Application)
    {
        Application->setWindowTitle(QApplication::translate("Application", "Form", Q_NULLPTR));
        tabMainWindow->setTabText(tabMainWindow->indexOf(tab), QApplication::translate("Application", "Current Registration", Q_NULLPTR));
        tabMainWindow->setTabText(tabMainWindow->indexOf(tab_2), QApplication::translate("Application", "Register For Classes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Application: public Ui_Application {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATION_H
