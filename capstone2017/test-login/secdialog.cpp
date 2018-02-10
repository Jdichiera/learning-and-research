#include "secdialog.h"
#include "ui_secdialog.h"


SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_btnConnectDatabase_clicked()
{
    qInfo() << "Clicked";
;}
