#pragma once
#include <mysql.h>
#include <string>
#include <iostream>
#include <vector>
#include "User.h"
#include "Message.h"
#include <thread>


class ConnectToDB {
    public:
		MYSQL mysql;
	private:
		MYSQL_RES* res;
		MYSQL_ROW row;
	public:
		ConnectToDB();
		~ConnectToDB();

        std::vector<User> getUserList();
        std::vector<Message> getAllMessage();
        int banUser(User user);
        int unplugUser(User user);
        bool userIsBanned(User user);


};

