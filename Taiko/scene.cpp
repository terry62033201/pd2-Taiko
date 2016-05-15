#include "scene.h"

Scene::Scene()
{
    screenMode = 0;
}

void Scene::Init(int x_start)
{
    // start
    btn_start = new Btn();
    QPixmap start;
    start.load(":/image/img/P.png");
    start = start.scaled(start.width()/10,start.height()/10,Qt::KeepAspectRatio);
    btn_w = (start.width())*3/2 - 60;
    btn_h = (start.height())*3/2 - 30;
    btn_start->setPixmap(start);
    btn_start->setPos(720,220);
    addItem(btn_start);

    //exit
    btn_exit = new Btn();
    QPixmap exit;
    exit.load(":/image/img/e.png");
    exit = exit.scaled(exit.width()/10, exit.height()/10, Qt::KeepAspectRatio);
    btn_w = (exit.width()) *3/2 - 60;
    btn_h = (exit.height()) *3/2 - 30;
    btn_exit->setPixmap(exit);
    btn_exit->setPos(920, 220);
    addItem(btn_exit);


    //  setting the boundary , only lowerBound has a little different
    leftBound = x_start-20;
    rightBound = leftBound+370;
    upperBound = 60;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(screenMode == 0)
    {
        if(event->scenePos().x() > btn_start->pos().x() && event->scenePos().x() <= btn_start->pos().x() + 50)
        {
            if(event->scenePos().y() > btn_start->pos().y() && event->scenePos().y() <= btn_start->pos().y() + 50)
            {
                cout << "Start!" << endl;
                bgChange();
                screenMode = 1;
            }
        }

        if(event->scenePos().x() > btn_exit->pos().x() && event->scenePos().x() <= btn_exit->pos().x() + 50)
        {
            if(event->scenePos().y() > btn_exit->pos().y() && event->scenePos().y() <= btn_exit->pos().y() +50)
            {
                cout << "Exit!" << endl;
                exit(1);
            }
        }
    }
    else if(screenMode == 1)
    {
        if(event->scenePos().x() > btn_back->pos().x() && event->scenePos().x() <= btn_back->pos().x() + 50)
        {
            if(event->scenePos().y() > btn_back->pos().y() && event->scenePos().y() <= btn_back->pos().y() + 50)
            {
                bgRecover();
                screenMode = 0;
            }

        }
    }

}

void Scene::bgChange()
{
    QImage bg;
    bg.load(":/image/img/bg.png");
    bg = bg.scaled(580,350);
    this->setBackgroundBrush(bg);
    removeItem(btn_start);
    removeItem(btn_exit);


    // Back buttom setting
    btn_back = new Btn();
    QPixmap bk;
    bk.load(":/image/img/Backbutton.gif");
    btn_small_w = bk.width()/4;
    btn_small_h = bk.height()/4;
    bk = bk.scaled(btn_small_w , btn_small_h, Qt::KeepAspectRatio);
    btn_back->setPixmap(bk);
    btn_back->setPos(1070,240);
    addItem(btn_back);

    tube = new Btn();
    QPixmap tu;
    tu.load(":/image/img/sfieldflash_blue.png");
    btn_small_w = tu.width()*2;
    btn_small_h = tu.height()*2-23;
    tu = tu.scaled(btn_small_w , btn_small_h, Qt::KeepAspectRatio);
    tube->setPixmap(tu);
    tube->setPos(570,84.4);
    addItem(tube);

    //DRUM
    drum = new Btn();

    dm.load(":/image/img/PI2.png");
    btn_small_w = dm.width()/3;
    btn_small_h = dm.height()/3;
    dm = dm.scaled(btn_small_w , btn_small_h, Qt::KeepAspectRatio);
    drum->setPixmap(dm);
    drum->setPos(570,70);
    addItem(drum);

    ball();

    for(int j = 0; j < 17; j++)
    {
        pinpong[j]->setPos(1075+500*j,120);
        addItem(pinpong[j]);
    }

    //MOVE
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(advance()));
    timer->start(20);

}

void Scene::bgRecover()
{
    removeItem(btn_back);
    removeItem(drum);
    removeItem(tube);
    for(int j = 0; j < 17; j++)
    {
        removeItem(pinpong[j]);
    }
    disconnect(timer,SIGNAL(timeout()),this,SLOT(advance()));

    QPixmap start;
    start.load(":/image/img/P.png");
    start = start.scaled(start.width()/10,start.height()/10,Qt::KeepAspectRatio);
    btn_w = (start.width())*3/2 - 60;
    btn_h = (start.height())*3/2 - 30;
    btn_start->setPixmap(start);
    btn_start->setPos(720,220);
    addItem(btn_start);

    QPixmap exit;
    exit.load(":/image/img/e.png");
    exit = exit.scaled(exit.width()/10, exit.height()/10, Qt::KeepAspectRatio);
    btn_w = (exit.width()) *3/2 - 60;
    btn_h = (exit.height()) *3/2 - 30;
    btn_exit->setPixmap(exit);
    btn_exit->setPos(920, 220);
    addItem(btn_exit);

    QImage bg;
    bg.load(":/image/img/25037_86336831AB1B4E321F95_1.jpeg");
    bg = bg.scaled(580,350);
    this->setBackgroundBrush(bg);
}

void Scene::ball()
{
    for(int i = 0; i < 40; i++)
    {
        random.push_back(qrand()%2 +1);
    }
    for(int i = 0; i < 40; i++)
    {
        if(random[i] == 1)
        {
            ball_y = new Ball();
            QPixmap bl_y;
            bl_y.load(":/image/img/y.png");
            bl_y = bl_y.scaled(bl_y.width()/10, bl_y.height()/10, Qt::KeepAspectRatio);
            btn_w = (bl_y.width()) *3/2 - 60;
            btn_h = (bl_y.height()) *3/2 - 30;
            ball_y->setPixmap(bl_y);
            pinpong.push_back(ball_y);
        }
        else if(random[i] == 2)
        {
            ball_w = new Ball();
            QPixmap bl_w;
            bl_w.load(":/image/img/w.png");
            bl_w = bl_w.scaled(bl_w.width()/10, bl_w.height()/10, Qt::KeepAspectRatio);
            btn_w = (bl_w.width()) *3/2 - 60;
            btn_h = (bl_w.height()) *3/2 -30;
            ball_w->setPixmap(bl_w);
            pinpong.push_back(ball_w);
        }

    }
}

void Scene::keyPressEvent(QKeyEvent *press)
{
    for(int j = 0; j < 17; j++)
    {
        if(random[j] == 1)
        {
            if(press->key()==Qt::Key_A)
            {
                    if(this->pinpong[j]->pos().x() > 560 && this->pinpong[j]->pos().x() < 650)
                    {
                        removeItem(pinpong[j]);
                        pinpong[j]->setPos(1150+500*j,120);
                        addItem(pinpong[j]);
                    }

            }
        }
        else if(random[j] == 2)
        {
            if(press->key()==Qt::Key_D)
            {

                    if(this->pinpong[j]->pos().x() > 560 && this->pinpong[j]->pos().x() < 650)
                    {
                        removeItem(pinpong[j]);
                        pinpong[j]->setPos(1150+500*j,120);
                        addItem(pinpong[j]);
                    }

            }
        }
    }
}
