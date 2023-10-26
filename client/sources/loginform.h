#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <memory>
#include "ConnectToDB.h"

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();
    void setDatabase(std::shared_ptr<ConnectToDB> dbPtr);

signals:
    void registerRequested();
    void accepted(QString userLog);
    void rejected();


private slots:


    void on_registrationPushButton_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::LoginForm *ui;
    std::shared_ptr<ConnectToDB> m_dbPtr;
};

#endif // LOGINFORM_H
