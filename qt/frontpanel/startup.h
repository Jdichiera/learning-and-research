#ifndef STARTUP_H
#define STARTUP_H
#include <QWidget>

class MainView;
class SetupTab;
class Startup final : public QObject
{
    Q_OBJECT
public:
    explicit Startup();
    void Show() const;

private:
    SetupTab& m_setupTab;
    MainView& m_mainView;
};
#endif // STARTUP_H

