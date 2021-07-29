#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString port_name="COM 5";
    int baud_rate=1500;
    ui->statusbar->showMessage(QString("Kameraya Bağlanıldı. Port Bilgisi: %1, Baud Rate=%2").arg(port_name).arg(baud_rate));
}

