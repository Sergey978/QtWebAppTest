#include "controller.h"

Controller::Controller(QObject* parent)
: HttpRequestHandler(parent)
{

}

 void Controller::service(HttpRequest &request, HttpResponse &response)
{

}


 HttpRequest * Controller::getHttpRequest()
 {
     return req;
 }

 HttpResponse * Controller::getHttpResponse()
 {
     return res;
 }

 void Controller::setHttpRequest( HttpRequest &req)
 {
     this->req = &req;
 }

 void Controller::setHttpResponse(HttpResponse &resp)
 {
     this->res = &resp;
 }

 void Controller::setReqResp(HttpRequest &req, HttpResponse &resp)
 {
      this->req = &req;
      this->res = &resp;
 }
