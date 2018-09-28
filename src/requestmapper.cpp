#include "requestmapper.h"
#include "httpsession.h"
#include "urlparams.h"
#include "fnptr.h"

HttpSessionStore* RequestMapper::sessionStore=0;
StaticFileController* RequestMapper::staticFileController=0;
TemplateCache* RequestMapper::templateCache=0;
Logger* RequestMapper::logger=0;


RequestMapper::RequestMapper(QObject* parent)
    : HttpRequestHandler(parent) {



    //registration Controllers
    //  matcher.regController("GET;home/about", [&](){});
    //  example:regController("GET|POST;user/edit/(id:num)",
    //  fnptr<void(UrlParams)>[&](UrlParams p){UserController.edit(p.Num("id"))});
    matcher.regController("GET;admin/user/(id:num)",
                         fnptr<void(UrlParams)>([&](UrlParams){adminController.user();}));

}

void RequestMapper::service(HttpRequest& request, HttpResponse& response) {
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());
    HttpSession session=sessionStore->getSession(request,response,false);
    QString username=session.get("username").toString();
    logger->set("currentUser",username);
    QByteArray sessionId=sessionStore->getSessionId(request,response);
    RequestMapper::req = &request;
    RequestMapper::res = &response;

    /*
    if (sessionId.isEmpty() && path!="/login") {
        qDebug("RequestMapper: redirect to login page");
        response.redirect("/login");
        return;
    }
    */


    //    if (path=="/" || path=="/hello") {
    //        helloWorldController.service(request, response);
    //    }

     Route * route = matcher.match(request.getMethod(), request.getPath().toStdString());
    matcher.execRoute(route);

    if (false) {
        helloWorldController.service(request, response);
    }

    else if (path=="/list") {
        listDataController.service(request, response);
    }
    else if (path=="/admin") {
        if (sessionId.isEmpty() || session.get("username") != "test" ) {
            qDebug("RequestMapper: redirect to login page");
            response.redirect("/login");
            return;
        }
        //adminController.service(request, response);
    }

    else if (path=="/login") {
        loginController.service(request, response);
    }
    else if (path=="/logout") {
        logoutController.service(request, response);
    }
    else if (path=="/cookie") {
        cookieTestController.service(request, response);
    }
    else if (path=="/list2") {
        dataTemplateController.service(request, response);
    }
    else if (path=="/bootstrap") {
        bootstrapController.service(request, response);
    }

    else if (path.startsWith("/files")) {
        staticFileController->service(request,response);
    }
    else {
        response.setStatus(404,"Not found");
        response.write("The URL is wrong, no such document.");
    }

    qDebug("RequestMapper: finished request");
    logger->clear(true,true);
}

HttpRequest * RequestMapper::getHttpRequest()
{
    return req;
}

HttpResponse * RequestMapper::getHttpResponse()
{
    return res;
}

