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
    Route(const std::string & route);
    void setRoute(const  std::string & route );
    bool urlMatch(const std::string & url, const QString & method,  UrlParams & params) ;
    QStringList getSplittedRoute() ;

private:
    QString stringRoute;
    QStringList  splittedRoute;
    QStringList splittedUrl;
    QStringList methods;
    QString extractMethods(const QString & route) noexcept(false);
    void _setRoute(const  std::string & route);

    QStringList methodList =
    {
        "GET",
        "POST"
    };

    QMap<QString, QString> patterns =
    {{"num" , "[0-9]+"},
     {"str", "[a-zA-Z\\.\\-_%]+"},
     {"any","[a-zA-Z0-9\\.\\-_%]+"}};
};

#endif // ROUTE_H
