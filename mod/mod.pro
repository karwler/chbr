TARGET = mod
TEMPLATE = lib
CONFIG += staticlib

INCLUDEPATH += include

SOURCES += src/filer.cpp \
        src/utils.cpp

HEADERS += include/filer.h \
        include/utils.h
