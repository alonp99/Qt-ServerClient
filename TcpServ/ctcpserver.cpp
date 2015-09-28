#include "ctcpserver.h"

cTcpServer::cTcpServer()
{

    QThreadPool::globalInstance()->setMaxThreadCount(10);
}

bool cTcpServer::startServer() // Server will listen on a random free port.
{
    if (this->listen(QHostAddress::Any)) {
        //serverAddress = this->serverAddress();
        m_serverPort = this->serverPort();
        qDebug() << "Server start listening on port: " << m_serverPort;
        return true;
    } else {
        m_serverError = this->serverError();
        qDebug() << "Server COULD NOT start listening on port: " << this->serverPort()
                 << ". (ERROR: " << m_serverError << " ).";
        return false;
    }
}

bool cTcpServer::startServer(int port) // Server will listen on a predefined port.
{
    if (this->listen(QHostAddress::Any,port)) {
        //serverAddress = this->serverAddress();
        m_serverPort = this->serverPort();
        qDebug() << "Server start listening on port: " << m_serverPort;
        return true;
    } else {
        m_serverError = this->serverError();
        qDebug() << "Server COULD NOT start listening on port: " << this->serverPort()
                 << ". (ERROR: " << m_serverError << " ).";
        return false;
    }
}

void cTcpServer::stopServer()
{
    qDebug() << "Server shutdown...";
    this->close();
}

void cTcpServer::incomingConnection(qintptr socketDescriptor)
{

    qDebug() << "New connection request from client #"<<socketDescriptor;
    cTcpSocket *newSocket = new cTcpSocket();
    newSocket->scktSetup(socketDescriptor);
    connect(newSocket,SIGNAL(finished()),newSocket,SLOT(deleteLater()));

    newSocket->start();

}

QAbstractSocket::SocketError cTcpServer::getServerError() const
{
    return m_serverError;
}

void cTcpServer::setServerError(const QAbstractSocket::SocketError &serverError)
{
    m_serverError = serverError;
}

//QHostAddress cTcpServer::getServerAddress() const
//{
//    return serverAddress;
//}

//void cTcpServer::setServerAddress(const QHostAddress &value)
//{
//    serverAddress = value;
//}

quint16 cTcpServer::getServerPort() const
{
    return m_serverPort;
}

void cTcpServer::setServerPort(const quint16 &value)
{
    m_serverPort = value;
}
