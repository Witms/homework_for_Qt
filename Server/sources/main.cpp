#include <iostream>
#include <mysql.h>
#include <QApplication>
#include "mainwindow.h"


int main(int argc, char* argv[])
{
  /*
    MYSQL *conn = mysql_init(nullptr);
    if(!mysql_real_connect(conn, "localhost", "messageclient@localhost", "mcl1", "test_database", 0, nullptr, 0))
    {
        std::cout << "Error mysql\n";
    }
    if(mysql_query(conn, "select * from message"))
    {
        std::cout << "Another error";
    }
    MYSQL_RES *res = mysql_use_result(conn);
    std::cout << "Resutl from MYSQL:\n";
    MYSQL_ROW row;
    while((row = mysql_fetch_row(res)) != nullptr)
    {
        std::cout << row[0] << std::endl;
    }
    mysql_free_result(res);
    mysql_close(conn);
	return 0;

    */

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
