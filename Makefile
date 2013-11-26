mysql_controller : test.cpp mysql_controller.h mysql_controller.h \
	database_controller.h
	g++ test.cpp mysql_controller.cpp -o msyql_controller -L/usr/lib/mysql \
		-lmysqlclient
