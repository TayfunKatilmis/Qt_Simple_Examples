#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "buraya istenilen bişey yazabilirsinizz";

    float sayi=10.5;
    qDebug() <<"Buraya sayılarda girilebilir sayı = "<< sayi;
}

MainWindow::~MainWindow()
{
    delete ui;
}

