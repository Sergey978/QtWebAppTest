#ifndef BOOTSTRAPTEMPLATE_H
#define BOOTSTRAPTEMPLATE_H


#include "httprequesthandler.h"

using namespace stefanfrings;


class BootstrapTemplateController: public HttpRequestHandler {
    Q_OBJECT
public:
    BootstrapTemplateController(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
private:
    QList<QString> list;
};

#endif // BOOTSTRAPTEMPLATE_H
