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
    std::string request = "select sender, recipient_user_log, text from links, messages where links.message_id = messages.id";
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

int ConnectToDB::banUser(User user)
{
    std::string request = "update users set is_banned = 1 where log =";
    std::string suffix = "'" + user.getLogin() + "'";
    request += suffix;
    mysql_query(&mysql, request.c_str());

    return 0;
}

int ConnectToDB::unplugUser(User user)
{
    std::string request = "update users set is_banned = 1 where log =";
    std::string suffix = "'" + user.getLogin() + "'";
    request += suffix;
    mysql_query(&mysql, request.c_str());

    std::this_thread::sleep_for(5000ms);

    request = "update users set is_banned = 0 where log =";
    suffix = "'" + user.getLogin() + "'";
    request += suffix;
    mysql_query(&mysql, request.c_str());

    return 0;
}

bool ConnectToDB::userIsBan(User user)
{
    std::string request = "select * from users where log =";
    std::string suffix = "'" + user.getLogin() + "'";
    request += suffix;
    mysql_query(&mysql, request.c_str());
    if(res = mysql_store_result(&mysql))
    {
        while(row = mysql_fetch_row(res))
        {
            if(row[0] == "false")
                return false;
            else
                return true;
        }
    }
}

