#ifndef BALL_H
#define BALL_H
#include <QGraphicsPixmapItem>

class Ball: public QGraphicsPixmapItem
{
public:
    Ball();
    int speed;
    void advance(int phase);
};

#endif // BALL_H
