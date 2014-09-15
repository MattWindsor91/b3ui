#include <QDataStream>
#include <QMessageBox>

#include "connection.h"
#include "ui_connection.h"

Connection::Connection(QWidget *parent, QString host, QString port) :
    QWidget(parent),
    ui(new Ui::Connection),
    info_model(this, host, port),
    socket(this)
{
    ui->setupUi(this);
    ui->info_view->setModel(&info_model);

    connect(&this->socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(Error(QAbstractSocket::SocketError)));
    connect(&this->socket, SIGNAL(readyRead()), this, SLOT(Read()));

    connect(this->ui->send, SIGNAL(clicked()), this, SLOT(SendRawCommand()));

    this->socket.connectToHost(host, port.toUInt());
}

Connection::~Connection()
{
    delete ui;
}

void Connection::Error(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("BAPS3UI"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("BAPS3UI"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("BAPS3UI"),
                                 tr("The following error occurred: %1.")
                                 .arg(this->socket.errorString()));
    }
}

void Connection::Read()
{
    QTextStream in(&this->socket);

    QString chunk = in.readAll();
    this->ui->console_view->appendPlainText(chunk);
}

void Connection::SendRawCommand()
{
    QString command = this->ui->send_text->text();

    QTextStream out(&this->socket);
    out << command << '\n';
    out.flush();

    this->ui->console_view->appendPlainText(command);
    this->ui->send_text->clear();
}
