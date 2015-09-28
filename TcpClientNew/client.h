#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "cmessage.h"

class client : public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = 0);
    bool clientConnect(QString ip,int port);
    void clientDisconnect();
    bool sendQMsg(QString);
    bool sendRegMsg(cMessage msg);
    bool sendSrctMsg(struct payload);
signals:

public slots:
    void readyRead();
private:
    QTcpSocket *sckt;
};

#endif // CLIENT_H
