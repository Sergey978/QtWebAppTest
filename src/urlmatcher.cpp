#include "urlmatcher.h"
#include <algorithm>
#include <string>
#include<regex>


UrlMatcher::UrlMatcher()
{

}


Route  UrlMatcher::match( const QString &method, const std::string & url)
{
    Route _matchedRoute;
    foreach( Route _r , routes.keys())
    {
        if (_r.urlMatch(url, method, params))
        {
            _matchedRoute =  _r;
        }
    }
    return  _matchedRoute;
}

void UrlMatcher::execRoute(const Route, UrlParams &params)
{

}


void UrlMatcher::regController(const QString method, const std::string route , void(*fn)(UrlParams) )
{
    QStringList routeMethods;
    QString _methods =  method.toUpper();

    if(   _methods.contains('|'))
    {
        routeMethods = _methods.split("|");
    }

    if(_methods == "*")
    {
        routeMethods = this->methods;
    }

    Route _route;
    _route.setRoute(route, routeMethods);
    routes.insert(_route, fn);

}


