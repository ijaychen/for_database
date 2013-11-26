/*************************************************************************
	> File Name: database_controller.h
	> Author: cjj
	> Created Time: 2013年11月26日 星期二 22时04分39秒
	> 说明：定义操作数据库的基本操作的虚基类
 ************************************************************************/

#ifndef DATABASE_CONTROLLER_H
#define DATABASE_CONTROLLER_H

class Database_Controller
{
public:
	virtual bool Connection(const char * host, const char * userName, const char * passwd, const char *database, unsigned int port) = 0;
	virtual bool DisConnection() = 0;
};

#endif
