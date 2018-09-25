#include "urlparams.h"

UrlParams::UrlParams()
{

}

void UrlParams::setStr(const QString key, const QString value)
{
    str.insert(key, value);
}

void UrlParams::setNum(const QString key, const int value)
{
    nums.insert(key, value);
}

QString UrlParams::Str(const QString key) noexcept(false)
{

    if (str.contains(key))
    {
         return str[key];
    }
   else
    {
        throw std::runtime_error("Str key not found");
    }
}

int UrlParams::Num(const QString key) noexcept(false)
{
    if (nums.contains(key))
    {
         return nums[key];
    }
   else
    {
        throw std::runtime_error("Nums key not found");
    }

}
