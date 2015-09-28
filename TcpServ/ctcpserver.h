#ifndef CTCPSERVER_H
#define CTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QThreadPool>
#include "ctcpsocket.h"

class cTcpServer : public QTcpServer
{

public:
    cTcpServer(); // random free port
    bool startServer();
    bool startServer(int port);
    void stopServer();

    //    QHostAddress getServerAddress() const;
    //    void setServerAddress(const QHostAddress &value);

    quint16 getServerPort() const;
    void setServerPort(const quint16 &value);

    QAbstractSocket::SocketError getServerError() const;
    void setServerError(const QAbstractSocket::SocketError &serverError);

protected:
    void incomingConnection(qintptr socketDescriptor);

private:
    QTcpServer *serv;
   // cTcpSocket *newSocket;

    // QHostAddress serverAddress;
    QAbstractSocket::SocketError m_serverError; // Last server error
    quint16 m_serverPort;





};

#endif // CTCPSERVER_H
