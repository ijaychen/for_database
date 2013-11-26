				操作mysql 的相关函数
0、初始化
	mysql_init(MYSQL*);
1、连接
	MYSQL* mysql_real_connect(MYSQL* mysql, const char * host, const char * user, const char * passwd, const char * db, unsigned int port, const char * unix_socket, unsigned long flag);
