#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    new_connect();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::critical_new_slot()
{
    int result=QMessageBox::critical(this,"Kritik mesaj","Kritik bir işlem emin misiniz?","Evet","Hayır");
    qDebug() << "sonuç=" <<result;
}

void MainWindow::warning_new_slot()
{
    int result= QMessageBox::warning(this,"Dikkatli uyarısı","Dikkat olmanız gerekiyor","Tamam");
    qDebug() <<"sonuç=" <<result;

}

void MainWindow::information_new_slot()
{
    int result= QMessageBox::information(this,"Bilgi","Bilgilendirme yapılacak","Tamam");

    qDebug() <<"sonuç =" <<result;
}

void MainWindow::question_new_slot()
{
    int result= QMessageBox::question(this,"Dikkatli uyarısı","Dikkat olmanız gerekiyor ","Tamam");
    qDebug()<<"sonuç=" <<result;
}

void MainWindow::ozel_kullanim_slot()
{
    QMessageBox messagebox;
    messagebox.setText("Sayınız Tek mi? Çift mi?");
    messagebox.setIcon(QMessageBox::Question);
    messagebox.setWindowTitle("Özel Kullanım");
    messagebox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    QAbstractButton *button_yes=messagebox.button(QMessageBox::Yes);
    button_yes->setText("Tek Sayılar");
    QAbstractButton *button_no=messagebox.button(QMessageBox::No);
    button_no->setText("Çift Sayılar");

    int result= messagebox.exec();
    int start;
    if(result==QMessageBox::Yes){
        start=1;
    }
    else if(result==QMessageBox::No)
    {
        start=0;
    }
    ui->comboBox->clear();
    for(int i=start;i<50;i+=2){
       ui->comboBox->addItem(QString::number(i));
    }
}

void MainWindow::new_connect()
{
    connect(ui->pushButton_critical,SIGNAL(clicked()),this,SLOT(critical_new_slot()));
    connect(ui->actioncritical,SIGNAL(triggered()),this,SLOT(critical_new_slot()));
    connect(ui->action123,SIGNAL(triggered()),this,SLOT(ozel_kullanim_slot()));
    connect(ui->pushButton_ozel_kullanim,SIGNAL(clicked()),this,SLOT(ozel_kullanim_slot()));
    connect(ui->pushButton_information,SIGNAL(clicked()),this,SLOT(information_new_slot()));
    connect(ui->actioninformation,SIGNAL(triggered()),this,SLOT(information_new_slot()));
    connect(ui->pushButton_question,SIGNAL(clicked()),this,SLOT(question_new_slot()));
    connect(ui->actionquestion,SIGNAL(triggered()),this,SLOT(question_new_slot()));
    connect(ui->pushButton_warning,SIGNAL(clicked()),this,SLOT(warning_new_slot()));
    connect(ui->actionwarning,SIGNAL(triggered()),this,SLOT(warning_new_slot()));
}

