TARGET = chbr
TEMPLATE = app
CONFIG += console c++11

INCLUDEPATH += ../mod/include

LIBS += -L$$OUT_PWD/../mod \
        -lmod

SOURCES += src/main.cpp
