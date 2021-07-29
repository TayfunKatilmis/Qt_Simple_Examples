#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene =new Scene(this);
    scene->setSceneRect(-250,-300,500,600);

    QGraphicsPixmapItem * pixItem=new QGraphicsPixmapItem(QPixmap(":/images/background.png"));
    scene->addItem(pixItem);



    pixItem->setPos(QPointF(0,0)-QPointF(pixItem->boundingRect().width()/2,pixItem->boundingRect().height()/2));


    ui->graphicsView->setScene(scene);



    scene->addBird();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startGameButton_clicked()
{
    scene->startGame();
}

