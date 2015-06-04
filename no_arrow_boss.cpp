#include "no_arrow_boss.h"
#include <cstdlib>
#include <QTimer>
#include "fireball.h"
#include <QGraphicsScene>
#include <QSoundEffect>

no_arrow_boss::no_arrow_boss(QPixmap pixmap, int movement, char c):QGraphicsPixmapItem(pixmap)
{
    direction = 4;
    effect = new QSoundEffect();
    effect->setSource(QUrl("qrc:/audio/win.wav"));
    effect->setLoopCount(1);
    effect->setVolume(0.25f);

    if(movement == 0 || movement == 1){
        vertical = true;
        horizontal = false;
        if(c == 'r'){
            fire_direction = 3;
        }
        else {
            fire_direction = 2;
        }
    }
    else if (movement == 2 || movement == 3){
        vertical = false;
        horizontal = true;
        if(c == 'd'){
            fire_direction = 1;
        }
        else {
            fire_direction = 0;
        }
    }

    QTimer* move_timer = new QTimer();
    if (horizontal){
        connect(move_timer,SIGNAL(timeout()),this,SLOT(horizontal_move()));
    }
    else {
        connect(move_timer,SIGNAL(timeout()),this,SLOT(vertical_move()));
    }
    move_timer->start(50);

    QTimer* direction_change = new QTimer();
    connect(direction_change,SIGNAL(timeout()),this,SLOT(random_motion_change()));
    direction_change->start(2000);
}

no_arrow_boss::~no_arrow_boss()
{
    effect->play();
}

void no_arrow_boss::horizontal_move()
{
    if(direction == 2){
        setPos(x()-5,y());
        if(x() < 30){
            direction = 4;
        }
    }
    if (direction == 3){
        setPos(x()+5,y());
        if(x() > 330){
            direction = 3;
        }
    }

    int fire = rand() % 10;
    if (fire == 1){
        fireball* ball = new fireball(fire_direction);
        ball->setPos(x(),y());
        ball->setScale(0.5);
        scene()->addItem(ball);
    }

}

void no_arrow_boss::random_motion_change()
{
    if(horizontal){
        direction = (rand() % 2) + 2;
    }
    if(vertical){
        direction = rand() % 2;
    }
}

void no_arrow_boss::vertical_move()
{
    if(direction == 0){
        setPos(x(),y() - 5);
        if(y() < 0){
            direction = 1;
        }
    }
    if (direction == 1){
        setPos(x(),y()+5);
        if(y() > 450){
            direction = 0;
        }
    }

    int fire = rand() % 10;
    if (fire == 1){
        fireball* ball = new fireball(fire_direction);
        ball->setPos(x(),y());
        ball->setScale(0.5);
        scene()->addItem(ball);
    }
}
