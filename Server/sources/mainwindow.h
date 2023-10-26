#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ConnectToDB.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void updateInformation();

    void on_banPushButton_clicked();

    void on_unplugPushButton_clicked();

private:
    Ui::MainWindow *ui;
    ConnectToDB* m_dbPtr;
};

#endif // MAINWINDOW_H
