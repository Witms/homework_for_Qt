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
    QLabel *label;
    QLabel *label_2;
    QPushButton *unplugPushButton;
    QPushButton *banPushButton;
    QLineEdit *targetUserLineEdit;
    QTextBrowser *userListTextBrowser;
    QTextBrowser *messageListTextBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 40, 54, 17));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(520, 40, 84, 17));
        label_2->setAlignment(Qt::AlignCenter);
        unplugPushButton = new QPushButton(centralwidget);
        unplugPushButton->setObjectName(QString::fromUtf8("unplugPushButton"));
        unplugPushButton->setGeometry(QRect(60, 360, 101, 31));
        banPushButton = new QPushButton(centralwidget);
        banPushButton->setObjectName(QString::fromUtf8("banPushButton"));
        banPushButton->setGeometry(QRect(200, 360, 101, 31));
        targetUserLineEdit = new QLineEdit(centralwidget);
        targetUserLineEdit->setObjectName(QString::fromUtf8("targetUserLineEdit"));
        targetUserLineEdit->setGeometry(QRect(60, 320, 251, 25));
        userListTextBrowser = new QTextBrowser(centralwidget);
        userListTextBrowser->setObjectName(QString::fromUtf8("userListTextBrowser"));
        userListTextBrowser->setGeometry(QRect(53, 81, 201, 16));
        messageListTextBrowser = new QTextBrowser(centralwidget);
        messageListTextBrowser->setObjectName(QString::fromUtf8("messageListTextBrowser"));
        messageListTextBrowser->setGeometry(QRect(433, 81, 281, 211));
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
