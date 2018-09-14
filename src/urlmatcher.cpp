#include "urlmatcher.h"
#include <algorithm>
#include <string>
#include<regex>


UrlMatcher::UrlMatcher()
{

}

void UrlMatcher::addPattern(const std::string name, const std::string pattern)
{
    patterns[name] = pattern;
}

std::string UrlMatcher::convertRoute(const std::string route)
{
    if(  std::string::npos != route.find('(')){
        return  route;
    };

    // std::string s ("there is a subsequence in the string\n");
    // std::regex e ("\\b(sub)([^ ]*)");   // matches words beginning by "sub"


     //my regexp
  //   std::string route ("/user/(id:num)/(name:any)");
    // std::regex er("([A-Za-z]+):([A-Za-z]+)");

     std::regex er("\\((\\w+):(\\w+)\\)");

     // using string/c-string (3) version:
    // std::cout << std::regex_replace (s,e,"sub-$2") << "/n";

    std::string result = std::regex_replace (route,er,"$2",std::regex_constants::format_no_copy);

   std::cout<< result <<"\n";

     std::cout << std::regex_replace (route,er,"$1?" + getPatternByName(result)  );


}

void UrlMatcher::match(const std::string method)
{
    // routes["GET"].begin();
}

std::string UrlMatcher::getPatternByName(const std::string &name)
{
    auto it = patterns.find(name);
        if (it != patterns.end())
          return  it->second;
        else
          /* not found ... */;
        return "";
}

std::vector<std::string> UrlMatcher::split(const std::string &str, const std::string &delim)
{
    std::vector<std::string> tokens;
        size_t prev = 0, pos = 0;
        do
        {
            pos = str.find(delim, prev);
            if (pos == std::string::npos) pos = str.length();
            std::string token = str.substr(prev, pos-prev);
            if (!token.empty()) tokens.push_back(token);
            prev = pos + delim.length();
        }
        while (pos < str.length() && prev < str.length());
        return tokens;
}


void UrlMatcher::regController(const std::string method, const std::string route , void(*fn)(UrlParams))
{
    std::string _methods = method;
    std::vector<std::string> routeMethods;
    std::transform(_methods.begin(), _methods.end(),_methods.begin(), ::toupper);

   if( std::string::npos !=  _methods.find('|'))
   {
       routeMethods = split(_methods, "|");
   }

   if(_methods == "*")
   {
       routeMethods = this->methods;
   }

     std::string converted =
             convertRoute(route);
}


