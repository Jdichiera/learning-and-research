#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "database.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLogin_clicked(){
    // Get the text from the username and password boxes
    QString username = ui->inputUsername->text();
    QString password = ui->inputPassword->text();

    QMessageBox::information(this, "clicked", username + password);

    if(username == "test" && password == "test"){
        QMessageBox::information(this, "Login", "Correct!");
        //MainWindow::ui->btnLogin->hide
        secDialog = new SecDialog(this);
        secDialog->show();
    }
    else {
        QMessageBox::warning(this, "Login", "Incorrect Pass!");
    }
}

void MainWindow::on_btnConnectDatabase_clicked(){
    QString username = ui->inputUsername->text();
    QString password = ui->inputPassword->text();
   Database database("localhost:3360", username, password);
   //QSqlDatabase::lastError();
    //qInfo() << "Clicked";
}
