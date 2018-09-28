#ifndef URLMATCHER_H
#define URLMATCHER_H

#include <QMap>
#include<QString>
#include"fnptr.h"
#include "urlparams.h"
#include"route.h"
#include "httprequesthandler.h"

using namespace stefanfrings;
class UrlMatcher
{
public:
    UrlMatcher();

    //registration Controllers
    //  example:regController("GET|POST;user/edit/(id:num)",
    //  fnptr<void(UrlParams)>[&](UrlParams p){UserController.edit(p.Num("id"))});
    void regController(const std::string route, void(*fn)(UrlParams));

    Route * match( const QString &method, const std::string & url);
    void execRoute( Route *key );

private:
   UrlParams params;
   QMap <Route * , void(*)(UrlParams)> routes ;

};

#endif // URLMATCHER_H
