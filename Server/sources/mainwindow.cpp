#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateInformation);
    timer->start(10);
    auto dbPtr = new ConnectToDB();
    m_dbPtr = dbPtr;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateInformation()
{
    std::vector<User> Users = m_dbPtr->getUserList();
    QString userList;
    for(auto user : Users)
    {
        userList.append(QString::fromStdString(user.getLogin() + "\n"));
    }

    if(ui->userListTextBrowser->toPlainText() != userList)
        ui->userListTextBrowser->setText(userList);


    std::vector<Message> Messages = m_dbPtr->getAllMessage();
    QString messageList;
    for(auto message : Messages)
    {
        messageList.append(QString::fromStdString("<" + message.getSender() + "> say to <" + message.getRecipient() + ">: " + message.getText() + "\n"));
    }

    if(ui->messageListTextBrowser->toPlainText() != messageList)
        ui->messageListTextBrowser->setText(messageList);
}

void MainWindow::on_banPushButton_clicked()
{
    QString target = ui->targetUserLineEdit->text();
    User targetUser(target.toStdString());
    m_dbPtr->banUser(targetUser);
}

void MainWindow::on_unplugPushButton_clicked()
{
    QString target = ui->targetUserLineEdit->text();
    User targetUser(target.toStdString());
    m_dbPtr->unplugUser(targetUser);
}
