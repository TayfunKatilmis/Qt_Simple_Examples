#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include "pillaritem.h"
#include<QTimer>
#include "birditem.h"


class Scene: public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent =nullptr);
    void addBird();
    void startGame();


    bool getGameOn() const;
    void setGameOn(bool newGameOn);
    void incrementScore();

    void setScore(int newScore);

private:
    void showGameOverGraphics();
    void hidenGameOverGraphics();

    void setUpPillarTimer();
    QTimer * pillarTimer;
    BirdItem * bird;
    bool gameOn;
    void cleanPillars();
    void freezeBirdAndPillarsInPlace();

    int score;
    int bestScore;

    QGraphicsPixmapItem * gameOverPix;
    QGraphicsTextItem * scoreTextItem;

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event)override;
};

#endif // SCENE_H
