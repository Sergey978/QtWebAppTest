#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "httprequesthandler.h"

using namespace stefanfrings;

class Controller: public HttpRequestHandler {
    Q_OBJECT
public:
    Controller( QObject* parent=0);
    virtual void service(HttpRequest& request, HttpResponse& response) = 0;

};

#endif // CONTROLLER_H
