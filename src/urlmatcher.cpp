#include "urlmatcher.h"
#include <algorithm>
#include <string>
#include<regex>


UrlMatcher::UrlMatcher()
{

}


Route * UrlMatcher::match( const QString &method, const std::string & url)
{

    foreach( Route *_r , routes.keys())
    {
        if (_r->urlMatch(url, method, params))
        {
            return   _r;
        }
    }
    return  nullptr;
}

void UrlMatcher::execRoute( Route  *key)
{

routes.value(key)(params);
}


void UrlMatcher::regController(const std::string route , void(*fn)(UrlParams) )
{    
    Route _route(route);
    routes.insert(&_route, fn);
}


