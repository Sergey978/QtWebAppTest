#include "bootstraptemplate.h"
#include "requestmapper.h"
#include "template.h"

BootstrapTemplateController::BootstrapTemplateController(Controller * contr ):controller(contr)

{

    list.append("Robert");
    list.append("Lisa");
    list.append("Hannah");
    list.append("Ludwig");
    list.append("Miranda");
    list.append("Fracesco");
    list.append("Kim");
    list.append("Jacko");
}

void BootstrapTemplateController::service()
{
    HttpRequest *request = controller->getHttpRequest();
    HttpResponse *response = controller->getHttpResponse();
    HttpSession session=RequestMapper::sessionStore->getSession(*request,*response,false);
    QString username=session.get("username").toString();
    QByteArray language=request->getHeader("Accept-Language");
    qDebug("language=%s",qPrintable(language));

   // response->setHeader("Content-Type", "text/html; charset=UTF-8");

    Template t=RequestMapper::templateCache->getTemplate("experiment",language);
    t.setVariable("name",username);
    t.setCondition("logged-in",!username.isEmpty());
    t.loop("row",list.size());
    for(int i=0; i<list.size(); i++) {
        QString number=QString::number(i);
        QString name=list.at(i);
        t.setVariable("row"+number+".number",number);
        t.setVariable("row"+number+".name",name);
    }
    response->write(t.toUtf8(),true);
}
