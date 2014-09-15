#ifndef CONNECTIONMODEL_H
#define CONNECTIONMODEL_H

#include <QAbstractTableModel>
#include <QVariant>

class ConnectionInfo : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ConnectionInfo(QObject *parent, QString host, QString port);

    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    int columnCount(const QModelIndex &parent) const;
    int rowCount(const QModelIndex &parent) const;

signals:

public slots:

private:
    QString host;
    QString port;
};

#endif // CONNECTIONMODEL_H
