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
#include "controller.h"


using namespace stefanfrings;

class RequestMapper : public HttpRequestHandler {
    Q_OBJECT
public:
    RequestMapper(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
    static HttpSessionStore* sessionStore;
    static StaticFileController* staticFileController;
    static TemplateLoader* templateLoader;
    static Logger* logger;




private:
    Controller contr;
    HelloWorldController helloWorldController;
    ListDataController listDataController;
    LoginController loginController;
    CookieTestController cookieTestController;
    DataTemplateController  templateController =  DataTemplateController(&contr) ;
    AdminController adminController = AdminController(&contr);
    BootstrapTemplateController bootstrapController = BootstrapTemplateController(&contr);
    LogOut logoutController;
    UrlMatcher  matcher;

};

#endif // REQUESTMAPPER_H
