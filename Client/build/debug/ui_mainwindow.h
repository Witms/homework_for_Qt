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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_another_client;
    QAction *actionCloseClient;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *YourMessageLabel;
    QLineEdit *messageLineEdit;
    QPushButton *publicMessageSendButton;
    QPushButton *privateMessageSendButton;
    QSplitter *splitter;
    QTextBrowser *publicChatBrowser;
    QTextBrowser *privateChatBrowser;
    QMenuBar *menubar;
    QMenu *menuOpen_another_client;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(669, 405);
        actionOpen_another_client = new QAction(MainWindow);
        actionOpen_another_client->setObjectName(QString::fromUtf8("actionOpen_another_client"));
        actionCloseClient = new QAction(MainWindow);
        actionCloseClient->setObjectName(QString::fromUtf8("actionCloseClient"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        YourMessageLabel = new QLabel(centralwidget);
        YourMessageLabel->setObjectName(QString::fromUtf8("YourMessageLabel"));

        horizontalLayout->addWidget(YourMessageLabel);

        messageLineEdit = new QLineEdit(centralwidget);
        messageLineEdit->setObjectName(QString::fromUtf8("messageLineEdit"));

        horizontalLayout->addWidget(messageLineEdit);

        publicMessageSendButton = new QPushButton(centralwidget);
        publicMessageSendButton->setObjectName(QString::fromUtf8("publicMessageSendButton"));

        horizontalLayout->addWidget(publicMessageSendButton);

        privateMessageSendButton = new QPushButton(centralwidget);
        privateMessageSendButton->setObjectName(QString::fromUtf8("privateMessageSendButton"));

        horizontalLayout->addWidget(privateMessageSendButton);


        verticalLayout->addLayout(horizontalLayout);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        publicChatBrowser = new QTextBrowser(splitter);
        publicChatBrowser->setObjectName(QString::fromUtf8("publicChatBrowser"));
        splitter->addWidget(publicChatBrowser);
        privateChatBrowser = new QTextBrowser(splitter);
        privateChatBrowser->setObjectName(QString::fromUtf8("privateChatBrowser"));
        splitter->addWidget(privateChatBrowser);

        verticalLayout->addWidget(splitter);

        verticalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 669, 22));
        menuOpen_another_client = new QMenu(menubar);
        menuOpen_another_client->setObjectName(QString::fromUtf8("menuOpen_another_client"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOpen_another_client->menuAction());
        menuOpen_another_client->addAction(actionOpen_another_client);
        menuOpen_another_client->addSeparator();
        menuOpen_another_client->addAction(actionCloseClient);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen_another_client->setText(QApplication::translate("MainWindow", "Open another client", nullptr));
        actionCloseClient->setText(QApplication::translate("MainWindow", "Close this client", nullptr));
        YourMessageLabel->setText(QApplication::translate("MainWindow", "Your message:", nullptr));
        publicMessageSendButton->setText(QApplication::translate("MainWindow", "Send to all", nullptr));
        privateMessageSendButton->setText(QApplication::translate("MainWindow", "Send private", nullptr));
        menuOpen_another_client->setTitle(QApplication::translate("MainWindow", "Main menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
