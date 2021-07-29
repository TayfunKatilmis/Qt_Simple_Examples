#include "birditem.h"
#include <QGraphicsScene>

BirdItem::BirdItem(QPixmap pixmap) : wingPosition(WingPosition::Up),wingDirection(0)
{
    setPixmap(pixmap);
    QTimer * birdWingsTimer=new QTimer(this);
    connect(birdWingsTimer,&QTimer::timeout,[=](){
        updatePixmap();

    });
    birdWingsTimer->start(80);


    groundPosition=scenePos().y()+290;
    yAnimation=new QPropertyAnimation(this,"y",this);
    yAnimation->setStartValue(scenePos().y());
    yAnimation->setEndValue(groundPosition);
    yAnimation->setEasingCurve(QEasingCurve::InQuad);
    yAnimation->setDuration(1000);

    rotationAnimation = new QPropertyAnimation(this,"rotation",this);


    //yAnimation->start();

}

qreal BirdItem::rotation() const
{
    return m_rotation;
}

qreal BirdItem::y() const
{
    return m_y;
}

void BirdItem::shootUp()
{
    yAnimation->stop();
    //rotationAnimation->stop();

    qreal curPosY=y();
    yAnimation->setStartValue(curPosY);
    yAnimation->setEndValue(curPosY - scene()->sceneRect().height()/8);
    yAnimation->setEasingCurve(QEasingCurve::OutQuad);
    yAnimation->setDuration(285);
    yAnimation->start();


    rotationAnimation=new QPropertyAnimation(this,"rotation",this);
    rotateTo(90,1200,QEasingCurve::InQuad);

    connect(yAnimation,&QPropertyAnimation::finished,[=](){
       fallToGroundIfNecessary();
    });

    rotateTo(-20,200,QEasingCurve::OutCubic);
}

void BirdItem::startFlying()
{
    yAnimation->start();
    rotateTo(90,1200,QEasingCurve::InQuad);
}

void BirdItem::freezeInPlace()
{
    yAnimation->stop();
    rotationAnimation->stop();
}


void BirdItem::updatePixmap(){
    if(wingPosition==WingPosition::Middle){
        if(wingDirection){
            setPixmap(QPixmap(":/images/bird.png"));
            wingPosition= WingPosition::Up;
            wingDirection=0;
        }else{
            setPixmap(QPixmap(":/images/bird.png"));
            wingPosition = WingPosition::Down;
            wingDirection=1;
        }
    }
    else{
        setPixmap(QPixmap(":/images/bird.png"));
        wingPosition=WingPosition::Middle;
    }
}

void BirdItem::setRotation(qreal rotation)
{
    m_rotation = rotation;
    QPointF c=boundingRect().center();
    QTransform t;
    t.translate(c.x(),c.y());
    t.rotate(rotation);
    t.translate(-c.x(),-c.y());
    setTransform(t);
}

void BirdItem::setY(qreal y)
{
    moveBy(0,y-m_y);
    m_y=y;
}

void BirdItem::rotateTo(const qreal &end, const int &duraction, const QEasingCurve &curve)
{
    rotationAnimation->setStartValue(rotation());
    rotationAnimation->setEndValue(end);
    rotationAnimation->setEasingCurve(curve);
    rotationAnimation->setDuration(duraction);

    rotationAnimation->start();
}

void BirdItem::fallToGroundIfNecessary()
{
    if(y()<groundPosition){
        rotationAnimation->stop();
       // yAnimation->stop();

        yAnimation->setStartValue(y());
        yAnimation->setEndValue(groundPosition);
        yAnimation->setEasingCurve(QEasingCurve::OutQuad);
        yAnimation->setDuration(1200);
        yAnimation->start();


        rotateTo(-90,1100,QEasingCurve::InCubic);
    }
}
