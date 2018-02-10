/********************************************************************************
** Form generated from reading UI file 'setuptab.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPTAB_H
#define UI_SETUPTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetupTab
{
public:
    QGroupBox *gbTcpIp;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *loTcpIpGroup;
    QPushButton *btnConnect;
    QPushButton *btnDisconnect;
    QVBoxLayout *loIpAddress;
    QLabel *lblIpAddress;
    QLineEdit *editIpAddress;
    QVBoxLayout *loPort;
    QLabel *lblPort;
    QLineEdit *editPort;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *SetupTab)
    {
        if (SetupTab->objectName().isEmpty())
            SetupTab->setObjectName(QStringLiteral("SetupTab"));
        SetupTab->resize(586, 300);
        gbTcpIp = new QGroupBox(SetupTab);
        gbTcpIp->setObjectName(QStringLiteral("gbTcpIp"));
        gbTcpIp->setGeometry(QRect(0, 0, 421, 77));
        horizontalLayout_2 = new QHBoxLayout(gbTcpIp);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        loTcpIpGroup = new QHBoxLayout();
        loTcpIpGroup->setObjectName(QStringLiteral("loTcpIpGroup"));
        btnConnect = new QPushButton(gbTcpIp);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/root/Images/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnConnect->setIcon(icon);

        loTcpIpGroup->addWidget(btnConnect);

        btnDisconnect = new QPushButton(gbTcpIp);
        btnDisconnect->setObjectName(QStringLiteral("btnDisconnect"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/root/Images/0.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDisconnect->setIcon(icon1);

        loTcpIpGroup->addWidget(btnDisconnect);


        horizontalLayout_2->addLayout(loTcpIpGroup);

        loIpAddress = new QVBoxLayout();
        loIpAddress->setObjectName(QStringLiteral("loIpAddress"));
        lblIpAddress = new QLabel(gbTcpIp);
        lblIpAddress->setObjectName(QStringLiteral("lblIpAddress"));

        loIpAddress->addWidget(lblIpAddress);

        editIpAddress = new QLineEdit(gbTcpIp);
        editIpAddress->setObjectName(QStringLiteral("editIpAddress"));

        loIpAddress->addWidget(editIpAddress);


        horizontalLayout_2->addLayout(loIpAddress);

        loPort = new QVBoxLayout();
        loPort->setObjectName(QStringLiteral("loPort"));
        lblPort = new QLabel(gbTcpIp);
        lblPort->setObjectName(QStringLiteral("lblPort"));

        loPort->addWidget(lblPort);

        editPort = new QLineEdit(gbTcpIp);
        editPort->setObjectName(QStringLiteral("editPort"));
        editPort->setMaximumSize(QSize(75, 16777215));

        loPort->addWidget(editPort);


        horizontalLayout_2->addLayout(loPort);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        retranslateUi(SetupTab);

        QMetaObject::connectSlotsByName(SetupTab);
    } // setupUi

    void retranslateUi(QWidget *SetupTab)
    {
        SetupTab->setWindowTitle(QApplication::translate("SetupTab", "Form", Q_NULLPTR));
        gbTcpIp->setTitle(QApplication::translate("SetupTab", "Tcp/IP", Q_NULLPTR));
        btnConnect->setText(QApplication::translate("SetupTab", "Connect", Q_NULLPTR));
        btnDisconnect->setText(QApplication::translate("SetupTab", "Disconnect", Q_NULLPTR));
        lblIpAddress->setText(QApplication::translate("SetupTab", "<html><head/><body><p><span style=\" font-size:10pt;\">IP Address:</span></p></body></html>", Q_NULLPTR));
        lblPort->setText(QApplication::translate("SetupTab", "<html><head/><body><p><span style=\" font-size:10pt;\">Port:</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetupTab: public Ui_SetupTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPTAB_H
