QT  += core
QT  -= gui
QT  += network

TARGET = MyFirstWebApp

CONFIG   += console c++14

TEMPLATE = app

SOURCES += src/main.cpp \
    src/helloworldcontroller.cpp \
    src/listdatacontroller.cpp \
    src/requestmapper.cpp \
    src/logincontroller.cpp \
    src/cookietestcontroller.cpp \
    src/datatemplatecontroller.cpp \
    src/startup.cpp \
    src/admincontroller.cpp \   
    src/logout.cpp \
    src/sqlite/sqlite3.c \
    src/bootstraptemplate.cpp \
    src/urlmatcher.cpp \
    src/urlparams.cpp \
    src/route.cpp \



HEADERS += \
    src/helloworldcontroller.h \
    src/listdatacontroller.h \
    src/requestmapper.h \
    src/logincontroller.h \
    src/cookietestcontroller.h \
    src/datatemplatecontroller.h \
    src/startup.h \
    src/admincontroller.h \
    src/logout.h \
    src/sqlite/sqlite3.h \
    src/sqlite_orm/sqlite_orm.h \
    src/bootstraptemplate.h \
    src/urlmatcher.h \
    src/urlparams.h \
    src/fnptr.h \
    src/route.h \




OTHER_FILES += etc/webapp1.ini \
     docroot/files/hello.html \
     docroot/listdata.html

include(../QtWebApp/QtWebApp/httpserver/httpserver.pri)
include(../QtWebApp/QtWebApp/templateengine/templateengine.pri)
include(../QtWebApp/QtWebApp/logging/logging.pri)
include(../QtWebApp/QtWebApp/qtservice/qtservice.pri)
