#-------------------------------------------------
#
# Project created by QtCreator 2015-09-13T15:33:06
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpServ
TEMPLATE = app

QMAKE_MAC_SDK = macosx10.11
SOURCES += main.cpp\
        servergui.cpp \
    ctcpsocket.cpp \
    ctcpserver.cpp \
    sharedressthon.cpp

HEADERS  += servergui.h \
    ctcpserver.h \
    ctcpsocket.h \
    sharedressthon.h

FORMS    += servergui.ui
