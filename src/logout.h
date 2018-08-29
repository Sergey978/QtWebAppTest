#ifndef LOGOUT_H
#define LOGOUT_H


#include "httprequesthandler.h"

using namespace stefanfrings;


class LogOut: public HttpRequestHandler {
    Q_OBJECT
public:
    LogOut(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
};

#endif // LOGOUT_H
