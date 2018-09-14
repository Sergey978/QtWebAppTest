#include "urlparams.h"
#include <map>

UrlParams::UrlParams()
{

}

void UrlParams::setStr(const std::string key, const std::string value)
{
    str.emplace(key, value);
}

void UrlParams::setNum(const std::string key, const int value)
{
    nums.emplace(key, value);
}

std::string UrlParams::Str(std::string key)
{
    auto it = str.find(key);
    if (it != str.end())
      return  it->second;
    else
      /* not found ... */;
    return "";
}

int UrlParams::Num(std::string key)
{
    auto it = nums.find(key);
    if (it != nums.end())
      return  it->second;
    else
      /* not found ... */;
    return 0;
}
