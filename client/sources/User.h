#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User
{
    string _login;
    string _password;
public:
    User();
    User(string login);
    User(string login, string password);
    string getLogin() const;
    string getPassword() const;
};


#endif // USER_H
