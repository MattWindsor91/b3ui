#include "connectdialog.h"
#include "connection.h"
#include "ui_connectdialog.h"

ConnectDialog::ConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDialog)
{
    ui->setupUi(this);
}

ConnectDialog::~ConnectDialog()
{
    delete ui;
}

QString ConnectDialog::Host()
{
    return ui->host->text();
}

QString ConnectDialog::Port()
{
    return ui->port->text();
}
