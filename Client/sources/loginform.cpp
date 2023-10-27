#include "loginform.h"
#include "ui_loginform.h"
#include <QMessageBox>

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);

}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::setDatabase(std::shared_ptr<ConnectToDB> dbPtr)
{
    m_dbPtr = dbPtr;
}


void LoginForm::on_registrationPushButton_clicked()
{
    emit registerRequested();
}

void LoginForm::on_buttonBox_accepted()
{
    User targetUser(ui->loginEdit->text().toStdString(), ui->passwordEdit->text().toStdString());

    auto correctPassword = m_dbPtr->checkPassword(targetUser);
    if(correctPassword == false)
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Password is wrong"));
        return;
    }
    if(m_dbPtr->userIsBanned(targetUser))
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("You are banned"));
        return;
    }

    emit accepted(ui->loginEdit->text());
}

void LoginForm::on_buttonBox_rejected()
{
    emit rejected();
}
