#pragma once
#include <mysql.h>
#include <string>
#include <iostream>
#include <vector>
#include "User.h"
#include "Message.h"



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
        bool checkPassword(User user);
        int addPublicMessage(Message message);
        int addPrivateMessage(Message message);
        std::vector<Message> getPublicMessage(User recipientUser);
        std::vector<Message> getPrivateMessage(User recipientUser);
        int addUser(User user);
        bool userIsBanned(User user);
        bool userExists(User user);


};

