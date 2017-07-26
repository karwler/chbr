QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chbrg
TEMPLATE = app
CONFIG += c++11

INCLUDEPATH += ../mod/include

LIBS += -L$$OUT_PWD/../mod \
        -lmod

SOURCES += src/main.cpp \
    src/mainWin.cpp

HEADERS  += src/mainWin.h

FORMS += src/mainWin.ui

RESOURCES += rsc/rsc.qrc
