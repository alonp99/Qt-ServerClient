#ifndef SERVERGUI_H
#define SERVERGUI_H

#include <QMainWindow>
#include <QNetworkInterface>
#include "ctcpserver.h"
#include "sharedressthon.h"

namespace Ui {
class ServerGUI;
}

class ServerGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerGUI(QWidget *parent = 0);
    ~ServerGUI();
public slots:
    void updateSocketsCounter();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    void setConnectedState();
    void setDisconnectedState();

    Ui::ServerGUI *ui;
    cTcpServer *server;

};

#endif // SERVERGUI_H
