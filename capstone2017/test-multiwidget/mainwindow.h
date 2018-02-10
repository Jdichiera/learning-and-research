#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

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
    void on_btnPage1Next_clicked();
    void on_btnPage2Next_clicked();
    void on_btnPage2Home_clicked();
    void on_btnPage3Home_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
