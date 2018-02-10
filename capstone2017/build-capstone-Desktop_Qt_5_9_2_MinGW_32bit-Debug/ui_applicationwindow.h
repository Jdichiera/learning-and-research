/********************************************************************************
** Form generated from reading UI file 'applicationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATIONWINDOW_H
#define UI_APPLICATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ApplicationWindow
{
public:
    QTabWidget *tabApplication;
    QWidget *tab;
    QWidget *tab_2;
    QTextBrowser *textUserInformation;

    void setupUi(QWidget *ApplicationWindow)
    {
        if (ApplicationWindow->objectName().isEmpty())
            ApplicationWindow->setObjectName(QStringLiteral("ApplicationWindow"));
        ApplicationWindow->resize(400, 300);
        tabApplication = new QTabWidget(ApplicationWindow);
        tabApplication->setObjectName(QStringLiteral("tabApplication"));
        tabApplication->setGeometry(QRect(16, 149, 371, 141));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabApplication->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabApplication->addTab(tab_2, QString());
        textUserInformation = new QTextBrowser(ApplicationWindow);
        textUserInformation->setObjectName(QStringLiteral("textUserInformation"));
        textUserInformation->setGeometry(QRect(10, 10, 381, 131));

        retranslateUi(ApplicationWindow);

        tabApplication->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ApplicationWindow);
    } // setupUi

    void retranslateUi(QWidget *ApplicationWindow)
    {
        ApplicationWindow->setWindowTitle(QApplication::translate("ApplicationWindow", "Form", Q_NULLPTR));
        tabApplication->setTabText(tabApplication->indexOf(tab), QApplication::translate("ApplicationWindow", "Current Registration", Q_NULLPTR));
        tabApplication->setTabText(tabApplication->indexOf(tab_2), QApplication::translate("ApplicationWindow", "Register For Classes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ApplicationWindow: public Ui_ApplicationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATIONWINDOW_H
