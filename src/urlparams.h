#ifndef URLPARAMS_H
#define URLPARAMS_H
# include <map>

class UrlParams
{
public:
    UrlParams();
    void setStr(const std::string key, const std::string value);
    void setNum(const std::string key, const int value);
    std::string Str(std::string key);
    int  Num(std::string key);
private:
     std::map<std::string, std::string> str;
    std::map<std::string, int> nums;
};

#endif // URLPARAMS_H
