#ifndef DATATEMPLATECONTROLLER_H
#define DATATEMPLATECONTROLLER_H

#include "httprequesthandler.h"
#include "controller.h"

using namespace stefanfrings;

class DataTemplateController {

public:
    DataTemplateController(Controller * contr);
    void service();
private:
    Controller * controller;
    QList<QString> list;
};

#endif // DATATEMPLATECONTROLLER_H
