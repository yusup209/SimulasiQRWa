#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    TcpServer(QObject *parent = nullptr);

public slots:
    void startTheServer();
    void stopTheServer();

private:
    QTcpServer *server;
    QTcpSocket *socket;
    bool stopServer = false;

private slots:
    void readyToRead();
    void newConnection();

signals:
    void qrIsShow();
    void loginSuccess();
    void closeConnection();
};

#endif // TCPSERVER_H
