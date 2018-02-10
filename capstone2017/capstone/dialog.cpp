#include "dialog.h"
#include "ui_dialog.h"

void Dialog::SetCourseID(int _id)
{
    ui->inputCourseId->setText(QString::number(_id));
}

void Dialog::SetType(QString _type)
{
    ui->inputCourseType->setText(_type);
}

void Dialog::SetSemester(QString _semester)
{
    ui->inputCourseSemester->setText(_semester);
}

void Dialog::SetCredits(int _credits)
{
    ui->inputCourseCredits->setText(QString::number(_credits));
}

void Dialog::SetDescription(QString _description)
{
    ui->inputCourseDescription->setText(_description);
}

void Dialog::SetName(QString _name)
{
    ui->inputCourseName->setText(_name);
}

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}



Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnCancel_clicked()
{
    this->done(0);
}

void Dialog::on_btnRegister_clicked()
{
    this->done(1);
}

Ui::Dialog *Dialog::getUi() const
{
    return ui;
}
