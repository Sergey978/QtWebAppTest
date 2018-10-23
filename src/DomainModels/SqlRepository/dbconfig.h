#ifndef DBCONFIG_H
#define DBCONFIG_H

#include <sqlpp11/mysql/mysql.h>
namespace mysql = sqlpp::mysql;
class DbConfig
{
public:
    static mysql::connection_config conf;
    static void   setConfig(std::string user, std::string database, bool debug){
        conf.user = user;
        conf.database = database;
        conf.debug = debug;
    }

};


#endif // DBCONFIG_H
