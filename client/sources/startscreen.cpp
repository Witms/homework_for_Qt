#include "startscreen.h"
#include "ui_startscreen.h"

StartScreen::StartScreen(std::shared_ptr<ConnectToDB> dbPtr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartScreen)
{
    ui->setupUi(this);

    if(dbPtr)
        m_dbPtr = dbPtr;
    else
        m_dbPtr = make_shared<ConnectToDB>();

    ui->loginWidget->setDatabase(m_dbPtr); // installing Database for loginWidget
    ui->registerWidget->setDatabase(m_dbPtr); // installing Database for registerWidget

    connect(ui->loginWidget, &LoginForm::registerRequested, this, &StartScreen::setRegistrationForm);
    connect(ui->loginWidget, &LoginForm::accepted, this, &StartScreen::onLoggedIn);
    connect(ui->loginWidget, &LoginForm::rejected, this, &StartScreen::onRejectRequested);
    connect(ui->registerWidget, &RegistrationForm::loginRequested, this, &StartScreen::setLoginForm);
    connect(ui->registerWidget, &RegistrationForm::accepted, this, &StartScreen::onLoggedIn);
    connect(ui->registerWidget, &RegistrationForm::rejected, this, &StartScreen::onRejectRequested);
}

StartScreen::~StartScreen()
{
    delete ui;
}

void StartScreen::setLoginForm()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void StartScreen::setRegistrationForm()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void StartScreen::onLoggedIn(QString userLog)
{
    m_userLog = userLog;
    accept();
}

void StartScreen::onRejectRequested()
{
    reject();
}

QString StartScreen::userLog() const
{
    return m_userLog;
}

std::shared_ptr<ConnectToDB> StartScreen::getDatabase() const
{
    return m_dbPtr;
}

