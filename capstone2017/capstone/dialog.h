#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    void SetCourseID(int _id);
    void SetType(QString _type);
    void SetSemester(QString _semester);
    void SetCredits(int _credits);
    void SetDescription(QString _description);
    void SetName(QString _name);
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    Ui::Dialog *getUi() const;

private slots:
    void on_btnCancel_clicked();

    void on_btnRegister_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
