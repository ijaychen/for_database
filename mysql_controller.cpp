/*************************************************************************
	> File Name: mysql_controller.cpp
	> Author: cjj
	> Created Time: 2013年11月26日 星期二 22时14分26秒
************************************************************************/
#include <iostream>
#include "mysql_controller.h"
using namespace std;

/***********************************************/
/*	* 函数名: Mysql_Controller
	* @param:
	* author:cjj
	* date:2013-11-27
	* 说明；构造函数
************************************************/
Mysql_Controller::Mysql_Controller()
{
	mysql_init(&m_sqlConnect);
	m_result = NULL;
}

/***********************************************/
/*	* 函数名: 
	* @param:
	* author:cjj
	* date:2013-11-27
	* 说明；析构函数
************************************************/
Mysql_Controller::~Mysql_Controller()
{
	mysql_close(&m_sqlConnect);
	if(m_result)
	{
		mysql_free_result(m_result);
		m_result = NULL;
	}
	m_columnName.clear();
}
 
/***********************************************/
/*	* 函数名:Connection
	* @param:
	* author:cjj
	* date:2013-11-27
	* 说明；
************************************************/
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

/***********************************************/
/*	* 函数名:
	* @param:
	* author:cjj
	* date:2013-11-27
	* 说明；
************************************************/
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

/***********************************************/
/*	* 函数名:
	* @param:
	* author:cjj
	* date:2013-11-27
	* 说明；
************************************************/
void * Mysql_Controller::ExecuteQuery(const char * szQueryStr, int len)
{
	if(!szQueryStr)
		return 0;
	try
	{
		int res = mysql_real_query(&m_sqlConnect, szQueryStr, len);
		if(0 != res)
		{
			cout << "查询失败, sql语句:" << szQueryStr << endl;
			return 0;
		}
		if(0 != m_result)
		{
			mysql_free_result(m_result);
			m_result = 0;
		}
		m_result = mysql_store_result(&m_sqlConnect);
		if(0 == m_result)
		{
			cout << "保存查询结果失败\n";
			return 0;
		}
		m_fileds = mysql_num_fields(m_result);
		MYSQL_FIELD * fileds = mysql_fetch_fields(m_result);
		for(int i = 0; i < m_fileds; i++)
		{
			m_columnName.push_back(fileds[i].name);
		}
	}
	catch(...)
	{
		cout << "捕捉到异常\n";
		return 0;
	}
}

/***********************************************/
/*	* 函数名:
	* @param:
	* author:cjj
	* date:2013-11-27
	* 说明；
************************************************/
int Mysql_Controller::ExecuteModify(const char * szModifyStr, int len)
{
	if(!szModifyStr)
	{
		cout << "sql语句为空\n";
		return -1;
	}
	int res = mysql_real_query(&m_sqlConnect, szModifyStr, len);
	if(0 != res)
	{
		cout << "执行sql语句出错，错误代码：" << res << endl;
		return -2;
	}
	if(m_result)
	{
		mysql_free_result(m_result);
		m_result = 0;
	}
	m_result = mysql_store_result(&m_sqlConnect);
	return 0;
}

/***********************************************/
/*	* 函数名:
	* @param:
	* author:cjj
	* date:2013-11-27
	* 说明；
************************************************/
int Mysql_Controller::GetFields() const
{
	return m_fileds;
}

/***********************************************/
/*	* 函数名:
	* @param:
	* author:cjj
	* date:2013-11-27
	* 说明；
************************************************/
std::vector<char*> Mysql_Controller::GetColumnName() const
{
	return m_columnName;
}

/***********************************************/
/*	* 函数名:
	* @param:
	* author:cjj
	* date:2013-11-27
	* 说明；
************************************************/
char ** Mysql_Controller::GetRow() const
{
	if(!m_result)
		return 0;
	return mysql_fetch_row(m_result);
}
