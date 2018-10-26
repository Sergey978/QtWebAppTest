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
    src/bootstraptemplate.cpp \
    src/urlmatcher.cpp \
    src/urlparams.cpp \
    src/route.cpp \
    src/controller.cpp \
    src/DomainModels/user.cpp \
    src/DomainModels/role.cpp \
    src/DomainModels/userrole.cpp \
    src/DomainModels/SqlRepository/dbconfig.cpp \
    src/DomainModels/SqlRepository/sqlrepository.cpp



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
    src/controller.h \
    src/DomainModels/user.h \
    src/DomainModels/SqlRepository/sqlite-test.h \
    src/DomainModels/role.h \
    src/DomainModels/userrole.h \
    src/DomainModels/SqlRepository/dbconfig.h \
    src/DomainModels/SqlRepository/sqlrepository.h \
    src/DomainModels/SqlRepository/dbcontext.h




OTHER_FILES += etc/webapp1.ini \
     docroot/files/hello.html \
     docroot/listdata.html

include(../QtWebApp/QtWebApp/httpserver/httpserver.pri)
include(../QtWebApp/QtWebApp/templateengine/templateengine.pri)
include(../QtWebApp/QtWebApp/logging/logging.pri)
include(../QtWebApp/QtWebApp/qtservice/qtservice.pri)
include(../QtWebApp/SQLpp11/sqlpp11-mysql-connector-lib.pri)





