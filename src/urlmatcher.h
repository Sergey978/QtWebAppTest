#ifndef URLMATCHER_H
#define URLMATCHER_H

#include <QMultiMap>
#include<QVector>
#include<QString>
#include"fnptr.h"
#include "urlparams.h"
#include"route.h"

class UrlMatcher
{
public:
    UrlMatcher();

    //registration Controllers
    // example : regController("GET|POST", "user/edit/(id:num)",
    //                     fnptr<void(UrlParams)>[&](UrlParams p){UserController.edit(p.Num("id"))});
    void regController(const QString method, const std::string route, void(*fn)(UrlParams));

    Route  match( const QString &method, const std::string & url);
    void execRoute(const Route, UrlParams &params );

private:
    QStringList methods=
    {
        "GET",
        "POST"
    };

    QMap<Route, void(*)(UrlParams)> routes ;
    UrlParams params;
};

#endif // URLMATCHER_H
