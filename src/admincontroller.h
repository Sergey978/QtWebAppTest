#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include "httprequesthandler.h"

using namespace stefanfrings;

class AdminController: public HttpRequestHandler {
    Q_OBJECT
public:
    AdminController(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
};
#endif // ADMINCONTROLLER_H
