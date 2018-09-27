#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include "httprequesthandler.h"

using namespace stefanfrings;

class AdminController: public HttpRequestHandler {
    Q_OBJECT
public:
    AdminController(HttpRequestHandler &par, QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
    void user( int id );

};
#endif // ADMINCONTROLLER_H
