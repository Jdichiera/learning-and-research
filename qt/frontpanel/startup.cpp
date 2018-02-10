#include "startup.h"
#include "View/setuptab.h"
#include "View/mainview.h"

Startup::Startup() :
    QObject(nullptr),
    m_setupTab(*new SetupTab(nullptr)),
    m_mainView(*new MainView(nullptr, m_setupTab))
{
}

void Startup::Show() const
{
    m_mainView.show();
}
