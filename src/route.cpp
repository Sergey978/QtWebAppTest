#include "route.h"


Route::Route(const std::string & route)
{
    setRoute(route);
}

void Route::setRoute(const std::string & route)
{
    stringRoute = QString::fromStdString(route);
    _setRoute(route);

}


bool Route::urlMatch(const std::string & url, const QString & method, UrlParams & params )
{
    QRegExp _rx;
    QString _url = QString::fromStdString(url);
    splittedUrl   = _url.split("/");
    if (!methods.contains(method))
    {
        return false;
    }

    if (splittedUrl.length() != splittedRoute.length())
    {
        return  false;
    }

    for (int i =0 ; i < splittedRoute.length() ; i++)
    {

        if (splittedRoute[i].contains("/"))
        {
            // _list[0] - name; _list[1] - type; _list[2] - pattern
            QStringList _list = splittedRoute[i].split("/");
            _rx = QRegExp(_list[2]);
            if( _rx.exactMatch(splittedUrl[i]))
            {
                if (_list[1] == "num")
                {
                    params.setNum(_list[0], splittedUrl[i].toInt());
                    continue;
                }
                else if (_list[1] == "str")
                {
                    params.setStr(_list[0], splittedUrl[i]);
                    continue;
                }
                else if (_list[1] == "any")
                {
                    params.setStr(_list[0], splittedUrl[i]);
                    continue;
                }

            }
            else
            {
                return false;
            }
        }
        else if (splittedRoute[i] != splittedUrl[i])
        {
            return false;
        }
    }
    return true;
}

QStringList Route::getSplittedRoute()
{
    return splittedRoute;
}

QString Route::extractMethods(const QString &route)
{

    QStringList _splitted =  route.split(";");


    QString _methods =  _splitted[0].toUpper();


    if(   _methods.contains('|'))
    {
        methods = _methods.split("|");
    }

    if(_methods == "*")
    {
        methods = this->methodList;
    }

    return _splitted[2];
}

void Route::_setRoute(const std::string &route)
{
    QString _route = QString::fromStdString(route);

    _route = extractMethods(_route);
    splittedRoute = _route.split("/");

    QRegExp _rx("\\((\\w+):(\\w+)\\)");

    for ( QString &part : splittedRoute)
    {
        if (part.contains("("))
        {
            int pos = _rx.indexIn(part);
            QStringList list = _rx.capturedTexts();
            if (patterns.contains(list[2]))
            {
                part = list[1] + "/" +
                        list[2] + "/" +
                        patterns.value(list[2]);

            }
        }
    }
}
