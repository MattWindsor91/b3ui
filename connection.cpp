#include "connection.h"
#include "ui_connection.h"

Connection::Connection(QWidget *parent, QString host, QString port) :
    QWidget(parent),
    ui(new Ui::Connection),
    info_model(this, host, port)
{
    ui->setupUi(this);
    ui->info_view->setModel(&info_model);
}

Connection::~Connection()
{
    delete ui;
}
