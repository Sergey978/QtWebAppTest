#ifndef ROUTE_H
#define ROUTE_H
#include <vector>
#include <regex>
#include<QString>
#include <QSet>
#include<QMap>
#include "urlparams.h"

class Route
{
public:
    Route();
    void setRoute(const  std::string & route, const QStringList & methods );
    void setRoute(const  std::string & route, QString method );
    bool urlMatch(const std::string & url, const QString & method,  UrlParams & params) ;
    QStringList getSplittedRoute() ;

private:
    QStringList  splittedRoute;
    QStringList splittedUrl;
    QStringList methods;
    void _setRoute(const  std::string & route);

    QMap<QString, QString> patterns =
    {{"num" , "[0-9]+"},
     {"str", "[a-zA-Z\\.\\-_%]+"},
     {"any","[a-zA-Z0-9\\.\\-_%]+"}};
};

#endif // ROUTE_H
