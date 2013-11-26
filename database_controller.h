/*************************************************************************
	> File Name: database_controller.h
	> Author: cjj
	> Created Time: 2013年11月26日 星期二 22时04分39秒
	> 说明：定义操作数据库的基本操作的虚基类
 ************************************************************************/

#ifndef DATABASE_CONTROLLER_H
#define DATABASE_CONTROLLER_H
#include <vector>
class Database_Controller
{
public:
	//连接到数据库
	virtual bool Connection(const char * host, const char * userName, const char * passwd, const char *database, unsigned int port) = 0;
	//断开连接
	virtual bool DisConnection() = 0;
	//执行查询命令
	virtual void * ExecuteQuery(const char * szQueryStr, int len) = 0;
	//获取结果集字段的个数
	virtual int GetFields() const = 0;
	//获取结果集的字段的名称
	virtual std::vector<char*> GetColumnName() const = 0;
	//获取字段的值（一次返回一行)
	virtual char ** GetRow() const = 0;
	//执行修改相关的操作
	virtual int ExecuteModify(const char * szModifyStr, int len) = 0;
};

#endif
