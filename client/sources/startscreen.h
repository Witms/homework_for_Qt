#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QDialog>
#include <memory>
#include "ConnectToDB.h"

namespace Ui {
class StartScreen;
}

class StartScreen : public QDialog
{
    Q_OBJECT

public:
    explicit StartScreen(std::shared_ptr<ConnectToDB> dbPtr = nullptr, QWidget *parent = nullptr);
    ~StartScreen();
    void setLoginForm();
    void setRegistrationForm();

    QString userLog() const;
    std::shared_ptr<ConnectToDB> getDatabase() const;

public slots:
    void onLoggedIn(QString userLog);
    void onRejectRequested();

private:
    Ui::StartScreen *ui;
    QString m_userLog;
    std::shared_ptr<ConnectToDB> m_dbPtr;
};

#endif // STARTSCREEN_H
