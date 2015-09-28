#include "client.h"
#include <QDataStream>

client::client(QObject *parent) : QObject(parent)
{
    sckt = new QTcpSocket();

}

bool client::clientConnect(QString ip, int port)
{
    sckt->connectToHost(ip,port);
    connect (sckt,SIGNAL(readyRead()),this,SLOT(readyRead()));
    if (sckt->waitForConnected())
        return true;
    else
        return false;
}

void client::clientDisconnect()
{
    sckt->close();
}

bool client::sendQMsg(QString text)
{
    if (sckt->write(text.toUtf8())!= -1) {
        //sent #imp
        return true;
    } else {
        //error
        return false;
    }
}

bool client::sendRegMsg(cMessage msg)
{
    QByteArray payload;
    QDataStream in(&payload,QIODevice::ReadWrite);
    in << msg.senderID<<msg.data;
    if (sckt->write(payload)!= -1) {
        //sent #imp
        return true;
    } else {
        //error
        return false;
    }
}

bool client::sendSrctMsg(payload)
{
    //sckt->write(payload);
    return true;
}

void client::readyRead()
{
    qDebug() << "SERVER: "<< sckt->readAll();
}

