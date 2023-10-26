#include "User.h"

User::User(string login) : _login(login)
{
}

User::User() : _login(""),  _password("")
{
}

User::User(string login, string password) :_login(login), _password(password)
{
}

string User::getLogin() const
{
    return _login;
}

std::string User::getPassword() const
{
    return _password;
}
