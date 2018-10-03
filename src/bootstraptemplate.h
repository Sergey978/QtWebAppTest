#ifndef BOOTSTRAPTEMPLATE_H
#define BOOTSTRAPTEMPLATE_H


#include "httprequesthandler.h"
#include "controller.h"

using namespace stefanfrings;


class BootstrapTemplateController {

public:
    BootstrapTemplateController(Controller * contr);
    void service();
private:
    Controller * controller;
    QList<QString> list;
};

#endif // BOOTSTRAPTEMPLATE_H
