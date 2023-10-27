#include "ConnectToDB.h"

ConnectToDB::ConnectToDB() {

	mysql_init(&mysql);
	if(&mysql == nullptr) {
		std::cout << "Error: can`t create MySQL-descriptor" << std::endl;
	}

    if(!mysql_real_connect(&mysql, "localhost", "messageclient@localhost", "mcl1", "chatDb", 0, NULL, 0)) {
		std::cout << "Error: can`t connect to database " << mysql_error(&mysql) << std::endl;
	}
	else {
		std::cout << "Success to set connect to database" << std::endl;
	}

	mysql_set_character_set(&mysql, "utf8");
	std::cout << "Connection characterset: " << mysql_character_set_name(&mysql) << std::endl;

}

ConnectToDB::~ConnectToDB() {
	mysql_close(&mysql);
}


std::vector<User> ConnectToDB::getUserList()
{
    std::string request = "select log from users";
    std::vector<User> result;
    mysql_query(&mysql, request.c_str());
    if(res = mysql_store_result(&mysql))
    {
        while(row = mysql_fetch_row(res))
        {
            result.push_back(User(row[0]));
        }
    }

    return result;
}

std::vector<Message> ConnectToDB::getAllMessage()
{
    std::string request = "select sender, text from messages";
    std::vector<Message> result;
    mysql_query(&mysql, request.c_str());
    if(res = mysql_store_result(&mysql))
    {
        while(row = mysql_fetch_row(res))
        {
            result.push_back(Message(row[0], row[1]));
        }
    }

    return result;
}

int ConnectToDB::banUser(User user)
{
    std::string request = "delete from users where log = ";
    std::string preffix = "'" + user.getLogin() + "'";
    request += preffix;
    mysql_query(&mysql, request.c_str());
    if(res = mysql_store_result(&mysql))
    {
        while(row = mysql_fetch_row(res))
        {

        }
    }
    return 0;
}

int ConnectToDB::unplugUser(User user)
{
    std::string request = "update users set is_unplug = 1 where log =";
    std::string preffix = "'" + user.getLogin() + "'";
    request += preffix;
    mysql_query(&mysql, request.c_str());
    if(res = mysql_store_result(&mysql))
    {
        while(row = mysql_fetch_row(res))
        {

        }
    }
    return 0;
}

bool ConnectToDB::checkPassword(User user)
{
    std::string request = "select exists(select * from users where log = ";
    std::string suffix = "'" + user.getLogin() + "' && passwd = '" + user.getPassword() + "')";
    request += suffix;
    mysql_query(&mysql, request.c_str());
    if(res = mysql_store_result(&mysql))
    {
        while(row = mysql_fetch_row(res))
        {
            if(std::string(row[0]) == "1")
                return true;
            else
                return false;
        }
    }
}

int ConnectToDB::addPublicMessage(Message message)
{
    std::string request = "insert messages(sender, text) values(";
    std::string preffix = "'" + message.getSender() + "', '" + message.getText() + "')";
    request += preffix;
    mysql_query(&mysql, request.c_str());

    request.clear();
    request = "select max(id) from messages;";
    mysql_query(&mysql, request.c_str());
    request.clear();

    std::string messageId;

    if(res = mysql_store_result(&mysql)) {
        while(row = mysql_fetch_row(res)) {
            messageId = row[0];
        }
    }

    request = "select log from users;";
    mysql_query(&mysql, request.c_str());
    request.clear();
    request = "insert into links(recipient_user_log, message_id) values";


    if(res = mysql_store_result(&mysql))
    {
        while(row = mysql_fetch_row(res))
        {

                request += "('";
                request += row[0];
                request += "', " + messageId + "),";

        }
    }

    request[request.length() - 1] = ';';
    mysql_query(&mysql, request.c_str());

    return 0;
}


int ConnectToDB::addPrivateMessage(Message message)
{
    std::string request = "insert messages(sender, text) values(";
    std::string preffix = "'" + message.getSender() + "', '" + message.getText() + "')";
    request += preffix;
    mysql_query(&mysql, request.c_str());

    request.clear();
    request = "select max(id) from messages;";
    mysql_query(&mysql, request.c_str());
    request.clear();

    std::string messageId;

    if(res = mysql_store_result(&mysql)) {
        while(row = mysql_fetch_row(res)) {
            messageId = row[0];
        }
    }

    request = "select log from users;";
    mysql_query(&mysql, request.c_str());
    request.clear();
    request = "insert into links(recipient_user_log, message_id, is_private) values";


    if(res = mysql_store_result(&mysql))
    {
        while(row = mysql_fetch_row(res))
        {
                if(row[0] == message.getRecipient())
                {
                request += "('";
                request += row[0];
                request += "', " + messageId + ", " + "1" + "),";
                }
        }
    }

    request[request.length() - 1] = ';';
    mysql_query(&mysql, request.c_str());

    return 0;
}

std::vector<Message> ConnectToDB::getPublicMessage(User recipientUser)
{
    std::string request = "select sender, recipient_user_log, text  from messages, links where is_private = 0 && links.message_id = messages.id && recipient_user_log = ";
    std::string suffix = "'" + recipientUser.getLogin() + "'";
    request += suffix;
    std::vector<Message> result;
    mysql_query(&mysql, request.c_str());
    if(res = mysql_store_result(&mysql))
    {
        while(row = mysql_fetch_row(res))
        {
            result.push_back(Message(row[0], row[1], row[2]));
        }
    }

    return result;
}

int ConnectToDB::addUser(User user)
{
    bool userExists = this->userExists(user);

    if(userExists)
        return -1;

    std::string request = "insert users(log, passwd) values(";
    std::string suffix = "'" + user.getLogin() + "', '" + user.getPassword() + "')";
    request += suffix;
    mysql_query(&mysql, request.c_str());

    return 0;
}

std::vector<Message> ConnectToDB::getPrivateMessage(User recipientUser)
{
    std::string request = "select sender, recipient_user_log, text  from messages, links where is_private = 1 && links.message_id = messages.id && ( recipient_user_log = ";
    std::string suffix = "'" + recipientUser.getLogin() + "' || messages.sender = '" + recipientUser.getLogin() + "')";
    request += suffix;
    std::vector<Message> result;
    mysql_query(&mysql, request.c_str());
    if(res = mysql_store_result(&mysql))
    {
        while(row = mysql_fetch_row(res))
        {
            result.push_back(Message(row[0], row[1], row[2]));
        }
    }

    return result;
}

bool ConnectToDB::userIsBanned(User user)
{
    std::string request = "select is_banned from users where log =";
    std::string suffix = "'" + user.getLogin() + "'";
    request += suffix;
    mysql_query(&mysql, request.c_str());
    if(res = mysql_store_result(&mysql))
    {
        while(row = mysql_fetch_row(res))
        {
            if(std::string(row[0]) == "0")
                return false;
            else
                return true;
        }
    }
}

bool ConnectToDB::userExists(User user)
{
    std::string request = "select exists(select * from users where log = ";
    std::string suffix = "'" + user.getLogin() + "')";
    request += suffix;
    mysql_query(&mysql, request.c_str());
    if(res = mysql_store_result(&mysql))
    {
        while(row = mysql_fetch_row(res))
        {
            if(std::string(row[0]) == "0")
                return false;
            else
                return true;
        }
    }
}

