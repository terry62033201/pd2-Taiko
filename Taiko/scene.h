#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QSound>
#include "btn.h"
#include "ball.h"
#include <QKeyEvent>


class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    /* function */
    Scene();
    void Init(int x_start); // For screen initialize
    void bgChange(); // For background change from start to game
    void bgRecover(); // For background change back to start page
    void gameInit(); // Start the game page
    void movingBlock(); // Moving block down
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void ball();

    /* Variable */
    // For button
    Btn *btn_start;
    Btn *btn_back;
    Btn *drum;
    Btn *tube;
    Btn *btn_exit;
    void keyPressEvent(QKeyEvent *press);


    int btn_w;
    int btn_h;
    int btn_small_w;
    int btn_small_h;

    //For ball
    QPixmap dm;
    Ball *ball_y;
    Ball *ball_w;

    QList<int> random;
    QList<Ball *> pinpong;

    // For timer
    QTimer *timer;
    /* Use to control the scene page */
    int screenMode;
    // For scene boundary
    int upperBound;
    int lowerBound;
    int leftBound;
    int rightBound;

};

#endif // SCENE_H
