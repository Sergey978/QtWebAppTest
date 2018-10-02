#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include "httprequesthandler.h"
#include "controller.h"

using namespace stefanfrings;

class AdminController {

public:
    AdminController(Controller * contr);

    void service();
    void user(int id);
    void userEdit(int id);
private:    
  Controller * controller;
  void render();

};
#endif // ADMINCONTROLLER_H
