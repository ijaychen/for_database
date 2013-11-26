/*************************************************************************
	> File Name: test.cpp
	> Author: cjj
	> Created Time: 2013年11月26日 星期二 22时26分35秒
 ************************************************************************/
#include "mysql_controller.h"

int main()
{
	Mysql_Controller mysqlOperator;
	mysqlOperator.Connection("localhost", "root", "root", "test", 3306);
	return 0;
}
