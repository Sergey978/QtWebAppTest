#include "dbcontext.h"

DbContext::DbContext(   mysql::connection_config &conf):
    mysql::connection ( std::shared_ptr<mysql::connection_config>{&conf})
{

}


