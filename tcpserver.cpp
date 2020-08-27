#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent)
{
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

void TcpServer::startTheServer(){
    if (!server->listen(QHostAddress::Any, 1234)){
        qDebug() << "could start tcp server";
    } else {
        qDebug() << "tcp server started";
    }
}

void TcpServer::stopTheServer(){
    server->close();
}

void TcpServer::newConnection(){
    socket = server->nextPendingConnection();

    socket->write("welcome aboard\r\n");
    socket->flush();
    socket->waitForBytesWritten(3000);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyToRead()));
}

void TcpServer::readyToRead(){
    QString hmm = socket->readAll();
    hmm = hmm.remove("\r\n", Qt::CaseSensitive);
    QString resp = "OK\r\n";
    qDebug() << hmm;

    if (hmm == "qr_show"){
        qDebug() << "qr is shown";
        socket->write(resp.toLatin1());
        socket->waitForBytesWritten(3000);
        emit qrIsShow();
    } else if (hmm == "login_success"){
        qDebug() << "login success";
        socket->write(resp.toLatin1());
        socket->waitForBytesWritten(3000);
        emit loginSuccess();
    } else if (hmm == "exit"){
        socket->write(resp.toLatin1());
        socket->waitForBytesWritten(3000);
        socket->close();
        delete socket;
        emit closeConnection();
    }
}
