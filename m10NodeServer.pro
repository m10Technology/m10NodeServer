QT += core
QT -= gui
QT += network

TARGET = m10NodeServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    server.cpp \
    m10thread.cpp \
    client.cpp \
    commandthread.cpp

HEADERS += \
    m10thread.h \
    server.h \
    client.h \
    commandthread.h

