#include "admincontroller.h"
#include "sqlite_orm/sqlite_orm.h"



AdminController::AdminController(QObject *parent)
    : HttpRequestHandler(parent)
{


}

void AdminController::service(HttpRequest &request, HttpResponse &response)
{




    response.write("Hello1 This is Admin Area",true);
}
