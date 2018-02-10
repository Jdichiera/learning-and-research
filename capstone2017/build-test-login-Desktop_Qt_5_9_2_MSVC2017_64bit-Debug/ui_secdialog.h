/********************************************************************************
** Form generated from reading UI file 'secdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECDIALOG_H
#define UI_SECDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SecDialog
{
public:
    QLabel *lblLogin;
    QPushButton *btnConnectDatabase;

    void setupUi(QDialog *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName(QStringLiteral("SecDialog"));
        SecDialog->resize(400, 300);
        lblLogin = new QLabel(SecDialog);
        lblLogin->setObjectName(QStringLiteral("lblLogin"));
        lblLogin->setGeometry(QRect(120, 110, 121, 61));
        btnConnectDatabase = new QPushButton(SecDialog);
        btnConnectDatabase->setObjectName(QStringLiteral("btnConnectDatabase"));
        btnConnectDatabase->setGeometry(QRect(150, 180, 111, 23));

        retranslateUi(SecDialog);

        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QDialog *SecDialog)
    {
        SecDialog->setWindowTitle(QApplication::translate("SecDialog", "Dialog", Q_NULLPTR));
        lblLogin->setText(QApplication::translate("SecDialog", "<html><head/><body><p><span style=\" font-size:12pt;\">You logged in!!</span></p></body></html>", Q_NULLPTR));
        btnConnectDatabase->setText(QApplication::translate("SecDialog", "Connect to db", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECDIALOG_H
