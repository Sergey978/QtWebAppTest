#include "admincontroller.h"
#include "sqlite_orm/sqlite_orm.h"
#include "requestmapper.h"



AdminController::AdminController( HttpRequestHandler & handler )

{
    this->handler = &handler;

}



void AdminController::service()
{


  //  response.write("Hello1 This is Admin Area",true);
}

void AdminController::user()
{


}
