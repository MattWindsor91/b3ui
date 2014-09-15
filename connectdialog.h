#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>
#include <QMdiArea>

namespace Ui {
class ConnectDialog;
}

class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDialog(QWidget *parent);
    ~ConnectDialog();

    QString Host();
    QString Port();

private:
    Ui::ConnectDialog *ui;
};

#endif // CONNECTDIALOG_H
