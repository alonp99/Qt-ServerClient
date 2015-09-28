#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Connect
    m_Client = new client();
    if(m_Client->clientConnect(ui->lineEdit->text(),ui->lineEdit_2->text().toInt())){
        ui->label_4->setText("Connected.");
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    m_Client->clientDisconnect();
    ui->label_4->setText("Disconnected.");
}

void MainWindow::on_pushButton_3_clicked()
{
     // QUICK MSG
    bool ok;
    //QInputDialog *inDlg = new QInputDialog();

    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("Quick Message:"), QLineEdit::Normal,
                                             "Text...", &ok);
    m_Client->sendQMsg(text);
}

void MainWindow::on_pushButton_4_clicked()
{
    // REGULAR MSG
bool ok;
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                             tr("Quick Message:"), QLineEdit::Normal,
                                             "Text...", &ok);
    int senderID = 321;
    cMessage msg;
    msg.data =text;
    msg.senderID = senderID;
    m_Client->sendRegMsg(msg);



}

void MainWindow::on_pushButton_5_clicked()
{
    struct payload data;
    data.color = 16;
    data.sender = "Dsadsa";
    data.sender = "Dsadsa";

}
