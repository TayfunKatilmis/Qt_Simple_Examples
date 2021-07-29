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


void MainWindow::on_action_blue_triggered()
{
    ui->statusbar->showMessage("Mavi ekran açıldı",3000);

}



void MainWindow::on_action_red_triggered()
{
    ui->statusbar->showMessage("Kırmızı ekran açıldı",3000);
}



void MainWindow::on_action_green_triggered()
{
    ui->statusbar->showMessage("Yeşil ekran açıldı",3000);
    ui->action_green->setToolTip("Yeşil yer");
}


