#include "bootstraptemplate.h"
#include "requestmapper.h"
#include "template.h"

#include <cassert>
#include <iostream>
#include <vector>
#include"DomainModels/SqlRepository/sqlrepository.h"
#include"DomainModels/user.h"


BootstrapTemplateController::BootstrapTemplateController(Controller * contr )
    :controller(contr)

{


}

void BootstrapTemplateController::service()
{
    HttpRequest *request = controller->getHttpRequest();
    HttpResponse *response = controller->getHttpResponse();
    HttpSession session=RequestMapper::sessionStore->getSession(*request,*response,false);
    QString username=session.get("username").toString();
    QByteArray language=request->getHeader("Accept-Language");
    qDebug("language=%s",qPrintable(language));

    Template t=RequestMapper::templateLoader->getTemplate("default/layout",language);
    Template footer = RequestMapper::templateLoader->getTemplate("default/footer");
    Template header = RequestMapper::templateLoader->getTemplate("default/header");
    Template navbar = RequestMapper::templateLoader->getTemplate("default/navbar");
    t.setVariable("footer", footer);
    t.setVariable("header", header);
    t.setVariable("navbar", navbar);
    t.setVariable("name",username);
    t.setCondition("logged-in",!username.isEmpty());


    SqlRepository ur;
    std::vector<Role> roles;
    std::vector<User> users = ur.getUsers();
    QString roleList = "";

    t.loop("row",users.size());
    int i = 0;
    for ( User & row : users )
    {
        QString rowNumb = QString::number(i);

        t.setVariable("row" + rowNumb + ".id", QString::number(row.getId()));
        t.setVariable("row" + rowNumb + ".name", QString::fromStdString( row.getUserName()));

        roles = row.getRoles();
        roleList.clear();
        for (const Role &role : roles)
        {
            roleList.append(QString::fromStdString( role.getRoleName()));
            roleList.append(" ");
        }
        t.setVariable("row" + rowNumb + ".roles" , roleList);

        i++;
    }

    response->write(t.toUtf8(),true);

}
