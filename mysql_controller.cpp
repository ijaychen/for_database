/*************************************************************************
	> File Name: mysql_controller.cpp
	> Author: cjj
	> Created Time: 2013年11月26日 星期二 22时14分26秒
************************************************************************/
#include <iostream>
#include "mysql_controller.h"
using namespace std;

Mysql_Controller::Mysql_Controller()
{
	mysql_init(&m_sqlConnect);
}

bool Mysql_Controller::Connection(const char * host, const char *userName,const char *passwd, const char * database, unsigned int port)
{
	try
	{
		if(!mysql_real_connect(&m_sqlConnect, host, userName, passwd,database, port, NULL, 0))
		{
			cout << "mysql connect failed\n";
			return false;
		}
		else
		{
			cout << "mysql connect success\n";
			return true;
		}
	}
	catch(...)
	{
		cout << "catch exception\n";
		return false;
	}
}

bool Mysql_Controller::DisConnection()
{
	try
	{
		mysql_close(&m_sqlConnect);
		return true;
	}
	catch(...)
	{
		return false;
	}
}
