#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnLogin_clicked();
    void on_btnConnectDatabase_clicked();

private:
    Ui::MainWindow *ui;
    // Pointer to the next screen
    SecDialog *secDialog;
};

#endif // MAINWINDOW_H
