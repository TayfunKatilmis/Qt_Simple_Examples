#ifndef BIRDITEM_H
#define BIRDITEM_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <QTimer>

class BirdItem:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)
    Q_PROPERTY(qreal y READ y WRITE setY)
public:
    explicit BirdItem(QPixmap pixmap);
    void freezeInPlace();
    qreal rotation() const;
    qreal y() const;

    void shootUp();

    void startFlying();

public slots:
    void setRotation(qreal rotation);

    void setY(qreal y);

    void rotateTo(const qreal &end,const int& duraction,const QEasingCurve& curve);

    void fallToGroundIfNecessary();
private:
    enum WingPosition{
        Up,
        Middle,
        Down
    };

    qreal m_rotation;
    qreal m_y;

    void updatePixmap();
    WingPosition wingPosition;
    bool wingDirection;
    QPropertyAnimation * yAnimation;
    QPropertyAnimation * rotationAnimation;
    qreal groundPosition;
    bool gameOn;

};



#endif // BIRDITEM_H
