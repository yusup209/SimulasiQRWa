#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <tcpserver.h>
#include <qrdialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void qrnyaMuncul();
    void loginSuksesNih();

    void startServer();
    void stopServer();

private:
    Ui::MainWindow *ui;
    TcpServer *tcpServer;
    QRDialog *qrDiag;
    bool serverToggle = false;
};
#endif // MAINWINDOW_H
