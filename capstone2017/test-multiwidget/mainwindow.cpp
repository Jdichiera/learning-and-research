#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_btnPage1Next_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btnPage2Home_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnPage2Next_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btnPage3Home_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
