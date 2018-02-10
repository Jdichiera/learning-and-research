#ifndef PAGES_H
#define PAGES_H

#include <QWidget>

namespace Ui {
class Pages;
}

class Pages : public QWidget
{
    Q_OBJECT

public:
    explicit Pages(QWidget *parent = 0);
    ~Pages();

private:
    Ui::Pages *ui;
};

#endif // PAGES_H
