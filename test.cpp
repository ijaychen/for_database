/*************************************************************************
	> File Name: test.cpp
	> Author: cjj
	> Created Time: 2013年11月26日 星期二 22时26分35秒
 ************************************************************************/
#include "mysql_controller.h"
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	Database_Controller * mysqlOperator = new Mysql_Controller;
	mysqlOperator->Connection("localhost", "root", "root", "test", 3306);
	char * szQuery = "select * from student";
	char * szModify = "insert into student values(\"ijaychen\", \"123456\", \"ijaychen@126.com\")";
	//char * szModify = "delete from student where user_Name = \"ijaychen\"";
	std::vector<char *> strColumn;
	mysqlOperator->ExecuteModify(szModify, strlen(szModify));
	mysqlOperator->ExecuteQuery(szQuery, strlen(szQuery));
	int fields = mysqlOperator->GetFields();
	strColumn = mysqlOperator->GetColumnName();
	std::vector<char*>::iterator iter = strColumn.begin();
	while(iter != strColumn.end())
	{
		cout << *iter++ << "\t";
	}
	cout << endl;
	char ** resultSet = mysqlOperator->GetRow();
	while(resultSet)
	{
		for(int j = 0; j < fields; ++j)
		{
			cout << resultSet[j] << "\t";
		}
		cout << endl;
		resultSet = mysqlOperator->GetRow();
	}

	return 0;
}
