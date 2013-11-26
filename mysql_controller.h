/*************************************************************************
	> File Name: mysql_controller.h
	> Author: cjj
	> Created Time: 2013年11月26日 星期二 22时02分19秒
	> 说明：定义mysql的操作类
 ************************************************************************/

#ifndef MYSQL_CONTROLLER_H
#define MYSQL_CONTROLLER_H

#include <mysql/mysql.h>
#include "database_controller.h"
class  Mysql_Controller : public Database_Controller
{
private:
	MYSQL m_sqlConnect;
public:
	Mysql_Controller();
	virtual bool Connection(const char * host,const char * userName, const char * passwd, const char * database, unsigned int port);
	virtual bool DisConnection();
};

#endif
