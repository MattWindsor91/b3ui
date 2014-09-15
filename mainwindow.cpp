#include "aboutdialog.h"
#include "connectdialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(About()));
    QObject::connect(ui->actionConnect, SIGNAL(triggered()), this, SLOT(Connect()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::About()
{
    AboutDialog adialog(this);
    adialog.exec();
}

void MainWindow::Connect()
{
    ConnectDialog cdialog(this);
    cdialog.exec();
}
