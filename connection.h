#ifndef CONNECTION_H
#define CONNECTION_H

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
};

#endif // CONNECTION_H
