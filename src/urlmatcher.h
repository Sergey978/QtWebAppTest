#ifndef URLMATCHER_H
#define URLMATCHER_H

#include <vector>
#include <iostream>
#include<map>

class UrlMatcher
{
public:
    UrlMatcher();
    void addPattern(const std::string name, const std::string pattern );
    void regMethod(const std::string method,
                   const std::string route, const std::string controller);

    void convertRoute(const std::string route);
    void replaceRoute(const std::string match);

    /**
         * @param $method
         * @param $uri
         * @return MatchedRoute
         */
   void  match(const std::string method,  )

private:
    std::vector<std::string> methods= {"GET", "POST"};
    std::map<std::string, std::vector<std::string>> routes =
    {
        {"GET", {""}},
        {"POST", {""}}
    };
    std::map <std::string, std::string> patterns =
    {
       { "num","[0-9]+"},
       { "str" , "[a-zA-Z\.\-_%]+"},
       {"any" , "[a-zA-Z0-9\.\-_%]+"}
    };

};

#endif // URLMATCHER_H
