#include "logout.h"
#include "requestmapper.h"

LogOut::LogOut(QObject* parent)
    :HttpRequestHandler(parent) {
    // empty

}


void LogOut::service(HttpRequest &request, HttpResponse &response) {
    HttpSession session=RequestMapper::sessionStore->getSession(request,response,true);
     QByteArray sessionId=RequestMapper::sessionStore->getSessionId(request,response);

   if (!sessionId.isEmpty() ) {
       RequestMapper::sessionStore->removeSession(session);
       response.redirect("/");
   }
}
