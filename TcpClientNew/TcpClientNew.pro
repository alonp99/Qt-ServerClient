#-------------------------------------------------
#
# Project created by QtCreator 2015-09-15T08:07:48
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpClientNew
TEMPLATE = app
QMAKE_MAC_SDK = macosx10.11


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp \
    cmessage.cpp

HEADERS  += mainwindow.h \
    cmessage.h \
    client.h

FORMS    += mainwindow.ui
