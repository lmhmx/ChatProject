#include "QtWidgetsApplication1.h"
# include<qtcpsocket.h>
# include <qnetwork.h>
# include <qdebug.h>
# include <qtcpserver.h>
QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    QTcpSocket* a = new QTcpSocket();
    QTcpServer* b = new QTcpServer();
    b->listen();
    connect(b, &QTcpServer::newConnection, [=]() {
        qDebug() << b->nextPendingConnection()->localPort();
        });
    ui.setupUi(this);
}
