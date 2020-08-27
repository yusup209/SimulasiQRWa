#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpServer = new TcpServer(this);
    qrDiag = new QRDialog(this);
    connect(tcpServer, SIGNAL(qrIsShow()), this, SLOT(qrnyaMuncul()));
    connect(tcpServer, SIGNAL(loginSuccess()), this, SLOT(loginSuksesNih()));
    connect(tcpServer, SIGNAL(closeConnection()), this, SLOT(stopServer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::qrnyaMuncul(){
    qDebug() << "noh, qrnya nongol..";

    qrDiag->setModal(true);
    qrDiag->show();
}

void MainWindow::loginSuksesNih(){
    qDebug() << "login sukses atuh";
    qrDiag->hide();
}

void MainWindow::startServer(){
    tcpServer->startTheServer();
    serverToggle = !serverToggle;
    ui->pushButton->setText("Stop The server");
}

void MainWindow::stopServer(){
    tcpServer->stopTheServer();
    serverToggle = !serverToggle;
    ui->pushButton->setText("Start The server");
}

void MainWindow::on_pushButton_clicked()
{
    //start the tcp server
    if (!serverToggle){
        startServer();
    } else {
        stopServer();
    }

}
