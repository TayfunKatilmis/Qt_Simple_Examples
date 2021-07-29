#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this,SIGNAL(buton_bas_1()),this,SLOT(label_bas_1()));
    connect(this,SIGNAL(buton_bas_1()),this,SLOT(label_bas_2()));
    connect(this,SIGNAL(buton_bas_1()),this,SLOT(label_bas_3()));

    connect(this,SIGNAL(buton_bas_3()),this,SIGNAL(buton_bas_1()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_pressed()
{
    emit buton_bas_3();
}


void MainWindow::on_pushButton_released()
{
    ui->label_1->setText(" ");
    ui->label_2->setText(" ");
    ui->label_3->setText(" ");

}
void MainWindow::label_bas_1()
{
    ui->label_1->setText("Slot-1");
    ui->label_2->setText("Slot-2");
    ui->label_3->setText("Slot-3");
}
void MainWindow::label_bas_2()
{
    ui->label_1->setText("Slot-1");
    ui->label_2->setText("Slot-2");
    ui->label_3->setText("Slot-3");
}
void MainWindow::label_bas_3()
{
    ui->label_1->setText("Slot-1");
    ui->label_2->setText("Slot-2");
    ui->label_3->setText("Slot-3");
}
