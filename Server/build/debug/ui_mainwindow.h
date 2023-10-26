/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *userListTextBrowser;
    QTextBrowser *messageListTextBrowser;
    QLineEdit *targetUserLineEdit;
    QPushButton *unplugPushButton;
    QPushButton *banPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        userListTextBrowser = new QTextBrowser(centralwidget);
        userListTextBrowser->setObjectName(QString::fromUtf8("userListTextBrowser"));

        gridLayout->addWidget(userListTextBrowser, 1, 0, 1, 2);

        messageListTextBrowser = new QTextBrowser(centralwidget);
        messageListTextBrowser->setObjectName(QString::fromUtf8("messageListTextBrowser"));

        gridLayout->addWidget(messageListTextBrowser, 1, 2, 1, 1);

        targetUserLineEdit = new QLineEdit(centralwidget);
        targetUserLineEdit->setObjectName(QString::fromUtf8("targetUserLineEdit"));

        gridLayout->addWidget(targetUserLineEdit, 2, 0, 1, 2);

        unplugPushButton = new QPushButton(centralwidget);
        unplugPushButton->setObjectName(QString::fromUtf8("unplugPushButton"));

        gridLayout->addWidget(unplugPushButton, 3, 0, 1, 1);

        banPushButton = new QPushButton(centralwidget);
        banPushButton->setObjectName(QString::fromUtf8("banPushButton"));

        gridLayout->addWidget(banPushButton, 3, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "userList", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "messageList", nullptr));
        unplugPushButton->setText(QApplication::translate("MainWindow", "unplug", nullptr));
        banPushButton->setText(QApplication::translate("MainWindow", "Ban", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
