#include "admincontroller.h"
#include "sqlite_orm/sqlite_orm.h"
#include "requestmapper.h"



AdminController::AdminController( Controller * contr ):controller(contr)
{

}



void AdminController::service()
{


  //  response.write("Hello1 This is Admin Area",true);
}

void AdminController::user(int id)
{


        QByteArray resp = "its user controller ";
        QString ids = QString::number(id);
        QString now=QTime::currentTime().toString("HH:mm:ss");


    controller->getHttpResponse()->write(resp );
    controller->getHttpResponse()->write(  now.toLatin1() );
    controller->getHttpResponse()->write(  ids.toLatin1() );



}

void AdminController::userEdit(int id)
{
    QByteArray resp = "its userEdit controller ";
    QString ids = QString::number(id);
    QString now=QTime::currentTime().toString("HH:mm:ss");


controller->getHttpResponse()->write(resp );
controller->getHttpResponse()->write(  now.toLatin1() );
controller->getHttpResponse()->write(  ids.toLatin1() );
}

void AdminController::render()
{

}
