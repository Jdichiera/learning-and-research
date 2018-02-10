#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    // Manually update text on button
    // tr is translatable
    ui->w_exitButton->setText(tr("Exit now!"));

    // Create a connection
    // Old way
    //connect(ui->w_exitButton, SIGNAL(clicked(bool)), SLOT(close()));

    // new way
    connect (ui->w_exitButton, &QPushButton::clicked, this, &QMainWindow::close);

    // Disconnect button
    ui->w_exitButton->disconnect();
}

MainView::~MainView()
{
    delete ui;
}
