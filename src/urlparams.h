#ifndef URLPARAMS_H
#define URLPARAMS_H
# include <QMap>
#include<QString>
#include"httprequesthandler.h"

using namespace stefanfrings;
class UrlParams
{
public:
    UrlParams();
    void setStr(const QString key, const QString value);
    void setNum(const QString key, const int value);
    QString Str(QString key) noexcept(false);
    int  Num(QString key) noexcept(false);
    HttpRequest *request;
    HttpResponse *response;
private:
    QMap<QString, QString> str;
    QMap<QString, int> nums;
};

#endif // URLPARAMS_H
