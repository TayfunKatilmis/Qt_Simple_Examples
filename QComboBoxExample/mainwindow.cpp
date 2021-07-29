#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->comboBox->clear();
    ui->comboBox->addItem("Seçiniz",1);
    ui->comboBox->addItem("Kırmızı",2);

    //ui->comboBox->addItems({"Seçiniz","Kırmızı","Mavi","Sarı"});
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << ui->comboBox->currentText();

    qDebug() << ui->comboBox->currentData();
}

