#ifndef BOOTSTRAPTEMPLATE_H
#define BOOTSTRAPTEMPLATE_H

#include "DomainModels/SqlRepository/sqlite-test.h"
#include "httprequesthandler.h"
#include "controller.h"


#ifdef SQLPP_USE_SQLCIPHER
#include <sqlcipher/sqlite3.h>
#else
#include <sqlite3/sqlite3.h>
#endif

#include <sqlpp11/custom_query.h>
#include <sqlpp11/sqlite3/sqlite3.h>
#include <sqlpp11/sqlpp11.h>

using namespace stefanfrings;
namespace sql = sqlpp::sqlite3;

class BootstrapTemplateController {

public:
    BootstrapTemplateController(Controller * contr);
    void service();
private:
    Controller * controller;
    QList<QString> list;

    sqlRepo::User user;
    sqlRepo::Role role;
    sqlRepo::UserRoles userRoles;
    sql::connection_config config;
};

#endif // BOOTSTRAPTEMPLATE_H
