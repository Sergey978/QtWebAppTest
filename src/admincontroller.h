#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include "httprequesthandler.h"

using namespace stefanfrings;

class AdminController {

public:
    AdminController( HttpRequestHandler & handler);
    void service();
    void user();
private:
    HttpRequestHandler * handler;

};
#endif // ADMINCONTROLLER_H
