#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setEnabled(true);
    ui->lineEdit->setValidator(new QIntValidator(0,100,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_pressed()
{
    //QString line_edit_text=ui->lineEdit->text();
    //qDebug() << line_edit_text;

    int line_edit_int=ui->lineEdit->text().toInt();
    ui->lineEdit->setText(QString::number(line_edit_int));
    qDebug() <<line_edit_int;
    //sadece tam sayı değeri girmesini istiyorsak headera ıntvalidator eklicez

}

