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
	//mysql句柄
	MYSQL m_sqlConnect;
	//结果集指针
	MYSQL_RES * m_result;
	//结果集的字段个数
	int m_fileds;
	//字段的名称
	std::vector<char*> m_columnName;
public:
	//构造函数
	Mysql_Controller();
	//析构函数
	virtual ~Mysql_Controller();
	//连接到数据库
	virtual bool Connection(const char * host,const char * userName, const char * passwd, const char * database, unsigned int port);
	//断开数据库的连接
	virtual bool DisConnection();
	//执行查询操作
	virtual void * ExecuteQuery(const char * szQueryStr, int len);
	//执行修改操作
	virtual int ExecuteModify(const char * szModifyStr, int len);
	//获取字段的个数
	virtual int GetFields() const;
	//获取字段的名称
	virtual std::vector<char*> GetColumnName() const;
	//获取结果集记录(每次返回一条记录)
	virtual char ** GetRow() const;
};

#endif
