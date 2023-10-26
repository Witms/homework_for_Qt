#include "registrationform.h"
#include "ui_registrationform.h"
#include <QMessageBox>

RegistrationForm::RegistrationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistrationForm)
{
    ui->setupUi(this);
}

RegistrationForm::~RegistrationForm()
{
    delete ui;
}

void RegistrationForm::setDatabase(std::shared_ptr<ConnectToDB> dbPtr)
{
    m_dbPtr = dbPtr;
}


void RegistrationForm::on_loginPushButton_clicked()
{
    emit loginRequested();
}

void RegistrationForm::on_buttonBox_accepted()
{
    if(ui->passwordEdit->text() != ui->passwordConfirmEdit->text())
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Passwords not match"));
        return;
    }

    User targetUser(ui->loginEdit->text().toStdString(),
                    ui->passwordEdit->text().toStdString());
    auto userId = m_dbPtr->addUser(targetUser);

    switch (userId) // add some result for addUser return valiable
    {
    case -1:
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Incorrect login"));
        return;
    case -2:
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Login already exists"));
        return;
    default:
        emit accepted(ui->loginEdit->text());
    }

}

void RegistrationForm::on_buttonBox_rejected()
{
    emit rejected();
}
