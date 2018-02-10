/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *btnRegister;
    QPushButton *btnCancel;
    QLabel *labelCourseId;
    QLabel *labelSemester;
    QLabel *labelCredits;
    QLabel *labelDescription;
    QLabel *labelType;
    QLineEdit *inputCourseId;
    QLineEdit *inputCourseType;
    QLineEdit *inputCourseSemester;
    QLineEdit *inputCourseCredits;
    QLineEdit *inputCourseDescription;
    QLabel *labelCourseName;
    QLineEdit *inputCourseName;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        btnRegister = new QPushButton(Dialog);
        btnRegister->setObjectName(QStringLiteral("btnRegister"));
        btnRegister->setGeometry(QRect(290, 240, 75, 23));
        btnCancel = new QPushButton(Dialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(210, 240, 75, 23));
        labelCourseId = new QLabel(Dialog);
        labelCourseId->setObjectName(QStringLiteral("labelCourseId"));
        labelCourseId->setGeometry(QRect(10, 30, 71, 21));
        labelSemester = new QLabel(Dialog);
        labelSemester->setObjectName(QStringLiteral("labelSemester"));
        labelSemester->setGeometry(QRect(10, 70, 61, 20));
        labelCredits = new QLabel(Dialog);
        labelCredits->setObjectName(QStringLiteral("labelCredits"));
        labelCredits->setGeometry(QRect(10, 90, 51, 20));
        labelDescription = new QLabel(Dialog);
        labelDescription->setObjectName(QStringLiteral("labelDescription"));
        labelDescription->setGeometry(QRect(10, 100, 91, 41));
        labelType = new QLabel(Dialog);
        labelType->setObjectName(QStringLiteral("labelType"));
        labelType->setGeometry(QRect(10, 50, 61, 21));
        inputCourseId = new QLineEdit(Dialog);
        inputCourseId->setObjectName(QStringLiteral("inputCourseId"));
        inputCourseId->setGeometry(QRect(80, 30, 254, 20));
        inputCourseId->setReadOnly(true);
        inputCourseType = new QLineEdit(Dialog);
        inputCourseType->setObjectName(QStringLiteral("inputCourseType"));
        inputCourseType->setGeometry(QRect(80, 50, 254, 20));
        inputCourseType->setReadOnly(true);
        inputCourseSemester = new QLineEdit(Dialog);
        inputCourseSemester->setObjectName(QStringLiteral("inputCourseSemester"));
        inputCourseSemester->setGeometry(QRect(80, 70, 254, 20));
        inputCourseSemester->setReadOnly(true);
        inputCourseCredits = new QLineEdit(Dialog);
        inputCourseCredits->setObjectName(QStringLiteral("inputCourseCredits"));
        inputCourseCredits->setGeometry(QRect(80, 90, 254, 20));
        inputCourseCredits->setReadOnly(true);
        inputCourseDescription = new QLineEdit(Dialog);
        inputCourseDescription->setObjectName(QStringLiteral("inputCourseDescription"));
        inputCourseDescription->setGeometry(QRect(80, 120, 291, 101));
        inputCourseDescription->setReadOnly(true);
        labelCourseName = new QLabel(Dialog);
        labelCourseName->setObjectName(QStringLiteral("labelCourseName"));
        labelCourseName->setGeometry(QRect(10, 10, 71, 21));
        inputCourseName = new QLineEdit(Dialog);
        inputCourseName->setObjectName(QStringLiteral("inputCourseName"));
        inputCourseName->setGeometry(QRect(80, 10, 254, 20));
        inputCourseName->setReadOnly(true);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        btnRegister->setText(QApplication::translate("Dialog", "Register", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("Dialog", "Cancel", Q_NULLPTR));
        labelCourseId->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:10pt;\">Course ID</span></p></body></html>", Q_NULLPTR));
        labelSemester->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:10pt;\">Semester</span></p></body></html>", Q_NULLPTR));
        labelCredits->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:10pt;\">Credits</span></p></body></html>", Q_NULLPTR));
        labelDescription->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:10pt;\">Description</span></p></body></html>", Q_NULLPTR));
        labelType->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:10pt;\">Type</span></p></body></html>", Q_NULLPTR));
        labelCourseName->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:10pt;\">Name</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
