#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    capwebcam.open(0);
    if(capwebcam.isOpened()==false){

        ui->txtXYRadius->appendPlainText("error : capwebcam bot accessed successfuly");
        return;
    }
    tmrTimer=new QTimer(this);
    connect(tmrTimer,SIGNAL(timeout()),this ,SLOT(processFrameAndUpdateGUI()));
    tmrTimer->start(20);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnPauseorResume_clicked()
{
    if(tmrTimer->isActive()==true){
        tmrTimer->stop();
        ui->btnPauseorResume->setText("resume");

    }else{
        tmrTimer->start(20);
        ui->btnPauseorResume->setText("pause");
    }

}

void MainWindow::processFrameAndUpdateGUI()
{
    capwebcam.read(matOriginal);
    if(matOriginal.empty()==true) return;

    cv::inRange(matOriginal,cv::Scalar(0,0,160),cv::Scalar(100,100,240),matProcessed);
    cv::GaussianBlur(matProcessed, matProcessed, cv::Size(0,0),0.1);
    cv::HoughCircles(matProcessed,vecCircles,cv::HOUGH_GRADIENT,2,matProcessed.rows/4,100,50,3,400);

    for(itrCircles=vecCircles.begin();itrCircles !=vecCircles.end();itrCircles++)
    {
        ui->txtXYRadius->appendPlainText(QString("ball position x=")+ QString::number((*itrCircles)[0]).rightJustified(4,' ')+
                QString(", y=") + QString::number((*itrCircles)[2]).rightJustified(7, ' '));

        cv::circle(matOriginal,cv::Point((int)(*itrCircles)[0],(int)(*itrCircles)[1]),2, cv::Scalar(0,5,0), cv::FILLED);
        cv::circle(matOriginal,cv::Point((int)(*itrCircles)[0],(int)(*itrCircles)[1]),(int)(*itrCircles)[2],cv::Scalar(0,0,10),3);
    }

    cv::cvtColor(matOriginal,matOriginal,cv::COLOR_BGR2RGB);
    QImage qimgOrginal((uchar*)matOriginal.data,matOriginal.cols,matOriginal.rows,matOriginal.step,QImage::Format_RGB888);
    QImage qimgProcessed((uchar*)matProcessed.data,matProcessed.cols,matProcessed.rows,matProcessed.step,QImage::Format_Indexed8);

    ui->lblOriginal->setPixmap((QPixmap::fromImage(qimgOrginal)));
    ui->lblProcessed->setPixmap(QPixmap::fromImage(qimgProcessed));
}



