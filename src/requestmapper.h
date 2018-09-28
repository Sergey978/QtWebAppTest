#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H

#include "httprequesthandler.h"
#include "httpsessionstore.h"
#include "helloworldcontroller.h"
#include "listdatacontroller.h"
#include "logincontroller.h"
#include "cookietestcontroller.h"
#include "staticfilecontroller.h"
#include "templatecache.h"
#include "datatemplatecontroller.h"
#include "logger.h"
#include "admincontroller.h"
#include"logout.h"
#include "staticfilecontroller.h"
#include"bootstraptemplate.h"
#include "urlmatcher.h"

using namespace stefanfrings;

class RequestMapper : public HttpRequestHandler {
    Q_OBJECT
public:
    RequestMapper(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
    static HttpSessionStore* sessionStore;
    static StaticFileController* staticFileController;
    static TemplateCache* templateCache;
    static Logger* logger;
    HttpRequest * getHttpRequest();
    HttpResponse * getHttpResponse();



private:
    HelloWorldController helloWorldController;
    ListDataController listDataController;
    LoginController loginController;
    CookieTestController cookieTestController;
    DataTemplateController dataTemplateController;
    AdminController adminController = AdminController(*this);
    BootstrapTemplateController bootstrapController;
    LogOut logoutController;
    UrlMatcher  matcher;
    HttpRequest * req;
    HttpResponse * res;
};

#endif // REQUESTMAPPER_H
