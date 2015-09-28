#include "ctcpsocket.h"
int cTcpSocket::openSocketCounter = 0;
cTcpSocket::cTcpSocket()
{
    //openSocketCounter = 0;
    //int cTcpSocket::openSocketCounter = 0;
}

void cTcpSocket::run()
{

    sckt = new QTcpSocket();

    sckt->setSocketDescriptor(socketDescriptor);
    connect(sckt,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(sckt,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);
    qDebug() << "- Socket started on thread #"<< QThread::currentThread();


    //Socket connect's
    qintptr alias = sckt->socketDescriptor();
    qDebug() << "Client #"<<alias<<" Connected:";
    qDebug() << "Peer Address: " << sckt->peerAddress().toString();
    qDebug() << "Peer port: " << sckt->peerPort();
    qDebug() << "Peer name: " << sckt->peerName();
//    mutex.lock();
//    openSocketCounter++;
//    mutex.unlock();
    SharedResSthon::getInstance()->changeOSCounter(1);
    qDebug() << "Total Clients Connected : " << openSocketCounter;
    QString msg = "Welcome, your socket aliasc is: ";
    msg += QString::number(alias);
    QByteArray a1 = msg.toLatin1();
    //qDebug() << "check1";

    sckt->write(a1);

    exec();
}

void cTcpSocket::scktSetup(qintptr socketDescriptor)
{
    this->socketDescriptor = socketDescriptor;

}

void cTcpSocket::readyRead()
{

    qDebug() << sckt->readAll();

}

void cTcpSocket::disconnected()
{

    sckt->deleteLater();
//    mutex.lock();
//    openSocketCounter--;
//    mutex.unlock();
    SharedResSthon::getInstance()->changeOSCounter(-1);
    qDebug() << "Client Disconnected: #"<<this->socketDescriptor<<"." << "Clients Connected: "<<openSocketCounter;

}

