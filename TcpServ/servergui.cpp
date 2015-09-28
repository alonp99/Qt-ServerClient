#include "servergui.h"
#include "ui_servergui.h"

ServerGUI::ServerGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerGUI)
{
    ui->setupUi(this);
    connect(SharedResSthon::getInstance(),SIGNAL(updateSocketCounter()),this,SLOT(updateSocketsCounter()));
    setDisconnectedState();
}

ServerGUI::~ServerGUI()
{
    delete ui;
}

void ServerGUI::updateSocketsCounter()
{
    ui->label_8->setText(QString::number(SharedResSthon::getInstance()->getOpenSocketsCounter()));
}

void ServerGUI::on_pushButton_clicked() // START SERVER
{
    server = new cTcpServer();
    if (server->startServer(1234)) {
        setConnectedState();
    } else {
        setDisconnectedState();
    }
}

void ServerGUI::setConnectedState()
{
    ui->label_4->setText("Connected.");
    ui->label_4->setStyleSheet("QLabel {color : green;}");
    QString serverAddress;
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
            serverAddress = address.toString();
    }
    ui->label_6->setText(serverAddress);
    ui->label_5->setText(QString::number(server->getServerPort()));
    ui->pushButton->setDisabled(true);
    ui->pushButton_2->setDisabled(false);
}

void ServerGUI::setDisconnectedState()
{
    ui->label_4->setText("Disconnected.");
    ui->label_4->setStyleSheet("QLabel {color : red;}");
    ui->label_6->setText("-");
    ui->label_5->setText("-");
    ui->pushButton->setDisabled(false);
    ui->pushButton_2->setDisabled(true);
}

void ServerGUI::on_pushButton_2_clicked()
{
    server->stopServer();
    setDisconnectedState();
}
