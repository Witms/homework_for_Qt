#include "mainwindow.h"
#include "startscreen.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QListWidget>
#include <QTimer>

int MainWindow::kInstanceCount = 0;

MainWindow::MainWindow(QString userLog, std::shared_ptr<ConnectToDB> dbPtr, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_userLog(userLog)
{
    ui->setupUi(this);
    kInstanceCount++;

    if(dbPtr)
        m_dbPtr = dbPtr;
    else
        m_dbPtr = make_shared<ConnectToDB>(); // ?
    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateChats);
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
    kInstanceCount--;
    if(kInstanceCount <= 0)
        qApp->exit(0);
}

MainWindow* MainWindow::createClient(std::shared_ptr<ConnectToDB> dbPtr)
{
    StartScreen s(dbPtr);
    auto result = s.exec();

    if(result == QDialog::Rejected)
    {
        return nullptr;
    }

    auto w = new MainWindow(s.userLog(), s.getDatabase()); // ?
    w->setAttribute(Qt::WA_DeleteOnClose);
    return w;
}


void MainWindow::on_messageLineEdit_returnPressed()
{
    on_publicMessageSendButton_clicked();
}

void MainWindow::on_publicMessageSendButton_clicked()
{
    Message sendMessage(m_userLog.toStdString(),
                        ui->messageLineEdit->text().toStdString());

    m_dbPtr->addPublicMessage(sendMessage); // ~
}

void MainWindow::on_privateMessageSendButton_clicked()
{
    QDialog dial(this);
    dial.setModal(true);
    auto l = new QVBoxLayout();
    dial.setLayout(l);
    auto userListWgt = new QListWidget(&dial);
    l->addWidget(userListWgt);
    auto buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok |
                                          QDialogButtonBox::Cancel,
                                          &dial);
    l->addWidget(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, &dial, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dial, &QDialog::reject);

    auto userList = m_dbPtr->getUserList();
    for(auto user : userList)
    {
        userListWgt->addItem(QString::fromStdString(user.getLogin())); // maybe need to add perenos stroke
    }

    userListWgt->setCurrentRow(0);

    auto result = dial.exec();

    if(result == QDialog::Accepted &&
       userListWgt->currentItem())
    {
        Message targetMessage(m_userLog.toStdString(),
                              userListWgt->currentItem()->text().toStdString(),
                              ui->messageLineEdit->text().toStdString());
        m_dbPtr->addPrivateMessage(targetMessage);
    }
}

void MainWindow::on_actionOpen_another_client_triggered()
{
    auto w = createClient(m_dbPtr);
    if(w)
        w->show();
}

void MainWindow::on_actionCloseClient_triggered()
{
    this->close();
}

void MainWindow::updateChats()
{
 User recipientUser(m_userLog.toStdString());
 auto chatMessages = m_dbPtr->getPublicMessage(recipientUser); // Pohoshe ne vce soobshenia nada
 QString chat;
 for(const auto &msg : chatMessages)
 {
     chat.append(QString::fromStdString("<" + msg.getSender() + "> say to all: " + msg.getText() + "\n" ));
 }
 if(ui->publicChatBrowser->toPlainText() != chat)
    ui->publicChatBrowser->setText(chat); // command for set text in TextBrowser

 chat.clear();
 auto privateMessages = m_dbPtr->getPrivateMessage(recipientUser);
 for(const auto &msg : privateMessages)
 {
     if(QString::fromStdString(msg.getRecipient()) != m_userLog)
     {
         continue;
     }
     QString prefix;
     if(m_userLog == QString::fromStdString(msg.getSender()))
     {
         prefix = tr("self message") + ": ";
     }
     else
     {
         prefix = "<" + QString::fromStdString(msg.getSender()) +
                 "> " + tr("say to you") + ": ";
     }
     chat.append(prefix + QString::fromStdString(msg.getText()) + "\n");
 }
 if(ui->privateChatBrowser->toPlainText() != chat)
    ui->privateChatBrowser->setText(chat);
}
