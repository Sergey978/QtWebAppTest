#ifndef DBCONEXT_H
#define DBCONEXT_H


#include <sqlpp11/mysql/mysql.h>
#include"dbconfig.h"
namespace mysql = sqlpp::mysql;

class DbContext:public mysql::connection
{
public:
    static DbContext& Instance()
    {
        static DbContext s;
        return s;
    }
private:

    DbContext():
        mysql::connection (std::shared_ptr<mysql::connection_config>{&DbConfig::conf}){}
   ~DbContext(){}

    DbContext(DbContext const&) = delete;
   DbContext& operator= (DbContext const&) = delete;
};

#endif // DBCONEXTSINGL_H
