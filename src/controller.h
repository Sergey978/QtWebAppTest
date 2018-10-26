#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "httprequesthandler.h"



using namespace stefanfrings;

class Controller : public HttpRequestHandler
{
    Q_OBJECT
public:
    Controller(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
    HttpRequest * getHttpRequest();
    HttpResponse * getHttpResponse();
    void setHttpRequest( HttpRequest & req);
    void setHttpResponse( HttpResponse & resp);
    void setReqResp(HttpRequest &req, HttpResponse &resp);




private:
    HttpRequest * req;
    HttpResponse * res;
};

#endif // CONTROLLER_H
