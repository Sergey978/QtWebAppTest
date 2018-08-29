#include "admincontroller.h"


AdminController::AdminController(QObject *parent)
    : HttpRequestHandler(parent)
{
    // empty
}

void AdminController::service(HttpRequest &request, HttpResponse &response)
{
    response.write("Hello1 This is Admin Area",true);
}
