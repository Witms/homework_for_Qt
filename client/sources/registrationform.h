#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QWidget>
#include <memory>
#include "ConnectToDB.h"

namespace Ui {
class RegistrationForm;
}

class RegistrationForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrationForm(QWidget *parent = nullptr);
    ~RegistrationForm();
    void setDatabase(std::shared_ptr<ConnectToDB> dbPtr);

signals:
    void loginRequested();
    void accepted(QString userName);
    void rejected();

private slots:
    void on_loginPushButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::RegistrationForm *ui;
    std::shared_ptr<ConnectToDB> m_dbPtr;
};

#endif // REGISTRATIONFORM_H
