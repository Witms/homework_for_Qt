#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "ConnectToDB.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString userLog,
                        std::shared_ptr<ConnectToDB> dbPtr = nullptr,
                        QWidget *parent = nullptr);
    ~MainWindow();
    static MainWindow* createClient(std::shared_ptr<ConnectToDB> dbPtr = nullptr);

    static int kInstanceCount;

private slots:

    void on_messageLineEdit_returnPressed();

    void on_publicMessageSendButton_clicked();

    void on_privateMessageSendButton_clicked();

    void on_actionOpen_another_client_triggered();

    void on_actionCloseClient_triggered();

    void updateChats();

    void banCheck();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<ConnectToDB> m_dbPtr;
    QString m_userLog;
};

#endif // MAINWINDOW_H
