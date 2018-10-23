#ifndef DBCONTEXT_H
#define DBCONTEXT_H

#include <sqlpp11/mysql/mysql.h>
#include <iostream>

namespace mysql = sqlpp::mysql;
class DbContext:public mysql::connection
{
public:
   DbContext(  mysql::connection_config &conf );

};

#endif // DBCONTEXT_H
