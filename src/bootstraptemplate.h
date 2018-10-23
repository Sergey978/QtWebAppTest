#ifndef BOOTSTRAPTEMPLATE_H
#define BOOTSTRAPTEMPLATE_H

#include "DomainModels/SqlRepository/sqlite-test.h"
#include "httprequesthandler.h"
#include "controller.h"


class BootstrapTemplateController {

public:
    BootstrapTemplateController(Controller * contr);
    void service();
private:
    Controller * controller;
    QList<QString> list;    
};

#endif // BOOTSTRAPTEMPLATE_H
