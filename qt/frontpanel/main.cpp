#include <QApplication>
#include "startup.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Startup start_up;
    start_up.Show();
    return a.exec();
}
