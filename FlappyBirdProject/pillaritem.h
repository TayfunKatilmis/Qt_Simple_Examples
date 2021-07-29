#ifndef PILLARITEM_H
#define PILLARITEM_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QGraphicsItemGroup>


class PillarItem: public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)

public:
    explicit PillarItem();
    ~PillarItem();
    //burda bişey var yazmadım
    qreal x() const;
    void freezeInPlace();


signals:
    void collideFail();


public slots:
    void setX(qreal x);



private:
    bool collidesWithBird();
    QGraphicsPixmapItem * topPillar;
    QGraphicsPixmapItem * bottomPillar;
    QPropertyAnimation* xAnimation;
    int yPos;
    bool pastBird;

    qreal m_x;



};

#endif // PILLARITEM_H
