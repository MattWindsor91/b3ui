#ifndef CONNECTION_H
#define CONNECTION_H

#include <QTcpSocket>
#include <QWidget>

#include "connectioninfo.h"

namespace Ui {
class Connection;
}

class Connection : public QWidget
{
    Q_OBJECT

public:
    explicit Connection(QWidget *parent, QString host, QString port);
    ~Connection();

private:
    Ui::Connection *ui;
    ConnectionInfo info_model;
    QTcpSocket socket;

private slots:
    void Error(QAbstractSocket::SocketError socketError);
    void Read();
    void SendRawCommand();
};

#endif // CONNECTION_H
