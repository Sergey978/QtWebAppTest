#include "bootstraptemplate.h"
#include "requestmapper.h"
#include "template.h"

#include <cassert>
#include <iostream>
#include <vector>



BootstrapTemplateController::BootstrapTemplateController(Controller * contr ):controller(contr)

{

        config.path_to_database = "e:/SQLite/sqlite-test.db";
        config.flags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE;
        config.debug = false;



}

void BootstrapTemplateController::service()
{
    HttpRequest *request = controller->getHttpRequest();
    HttpResponse *response = controller->getHttpResponse();
    HttpSession session=RequestMapper::sessionStore->getSession(*request,*response,false);
    QString username=session.get("username").toString();
    QByteArray language=request->getHeader("Accept-Language");
    qDebug("language=%s",qPrintable(language));

     sql::connection db(config);


    auto sj =  db(select(user.id, user.name, role.roleName)
                .from(user.join(userRoles).on(user.id == userRoles.userId)
                .join(role).on(userRoles.RoleId == role.id)).unconditionally());



    Template t=RequestMapper::templateLoader->getTemplate("default/layout",language);
    Template footer = RequestMapper::templateLoader->getTemplate("default/footer");
    Template header = RequestMapper::templateLoader->getTemplate("default/header");
    Template navbar = RequestMapper::templateLoader->getTemplate("default/navbar");
    t.setVariable("footer", footer);
    t.setVariable("header", header);
    t.setVariable("navbar", navbar);
    t.setVariable("name",username);
    t.setCondition("logged-in",!username.isEmpty());


    int rowCount = 2;

    int i = 0;
    t.loop("row",50);
    for (const auto& row :  sj )
         {
            QString rowNumb = QString::number(i);
             t.setVariable("row" + rowNumb + ".id",QString::number(row.id));
             t.setVariable("row"+rowNumb+".name",QString::fromStdString( row.name));
             t.setVariable("row"+rowNumb+".roleName", QString::fromStdString(row.roleName));
             i++;
         }

    t.loop("row",4);
    response->write(t.toUtf8(),true);
}
