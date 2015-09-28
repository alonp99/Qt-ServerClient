#ifndef CTCPSOCKET_H
#define CTCPSOCKET_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QHostAddress>
#include "sharedressthon.h"


class cTcpSocket :public QThread
{
    Q_OBJECT
public:
    cTcpSocket();
    void run();
    void scktSetup(qintptr socketDescriptor);
    static int openSocketCounter;
private:
    QTcpSocket *sckt;
    qintptr socketDescriptor;
    QMutex mutex;



signals:

public slots:
    void readyRead();
    void disconnected();
};






#endif // CTCPSOCKET_H


