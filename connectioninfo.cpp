#include <QVariant>
#include <QAbstractItemModel>
#include <QAbstractTableModel>

#include "connectioninfo.h"

ConnectionInfo::ConnectionInfo(QObject *parent, QString host, QString port) :
    QAbstractTableModel(parent),
    host(host),
    port(port)
{
}

int ConnectionInfo::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return 2;
}

int ConnectionInfo::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return 2;
}

QVariant ConnectionInfo::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0: return QVariant(QString("Key"));
        case 1: return QVariant(QString("Value"));
        }
    }

    return QVariant();
}

QVariant ConnectionInfo::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0:
            switch (index.row()) {
            case 0: return QVariant(QString("Host"));
            case 1: return QVariant(QString("Port"));
            }
            break;
        case 1:
            switch (index.row()) {
            case 0: return QVariant(this->host);
            case 1: return QVariant(this->port);
            }
            break;
        }
    }
    return QVariant();
}
