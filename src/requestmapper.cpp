#include "requestmapper.h"
#include "httpsession.h"

HttpSessionStore* RequestMapper::sessionStore=0;
StaticFileController* RequestMapper::staticFileController=0;
TemplateCache* RequestMapper::templateCache=0;
Logger* RequestMapper::logger=0;

RequestMapper::RequestMapper(QObject* parent)
    : HttpRequestHandler(parent) {
    // empty
  //  matcher.regController("GET;home/about", [&](){});

    //registration Controllers
    //  example:regController("GET|POST;user/edit/(id:num)",
    //  fnptr<void(UrlParams)>[&](UrlParams p){UserController.edit(p.Num("id"))});

}

void RequestMapper::service(HttpRequest& request, HttpResponse& response) {
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());
    HttpSession session=sessionStore->getSession(request,response,false);
    QString username=session.get("username").toString();
    logger->set("currentUser",username);
    this->request = &request;
    this->response = &response;



    QByteArray sessionId=sessionStore->getSessionId(request,response);
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
        adminController.service(request, response);
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

