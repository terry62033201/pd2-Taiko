#include "ball.h"

Ball::Ball()
{
    speed = 1;
}

void Ball::advance(int phase)
{
    this->setPos(this->pos().x()-speed,this->pos().y());
}
