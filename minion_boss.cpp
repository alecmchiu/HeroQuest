#include "minion_boss.h"
#include "slime.h"
#include <cstdlib>
#include <QTimer>
#include "fireball.h"
#include <QGraphicsScene>
#include "arrow.h"
#include <QSoundEffect>

minion_boss::minion_boss(QPixmap pixmap, int movement, char c):QGraphicsPixmapItem(pixmap)
{
    direction = 4;
    effect = new QSoundEffect();
    effect->setSource(QUrl("qrc:/audio/win.wav"));
    effect->setLoopCount(1);
    effect->setVolume(0.25f);

    slime_number = 0;
    vulnerable = false;

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

    QTimer* minion_timer = new QTimer();
    connect(minion_timer,SIGNAL(timeout()),this,SLOT(spawn_slime()));
    minion_timer->start(5000);
}

minion_boss::~minion_boss()
{
    effect->play();
}

void minion_boss::horizontal_move()
{
    QList<QGraphicsItem*> list = collidingItems();
    for (auto w : list){
        if(vulnerable){
            if(typeid(*w) == typeid(Arrow)){
                scene()->removeItem(w);
                scene()->removeItem(this);
                delete w;
                delete this;
                return;
            }
        }
    }

    if(direction == 2){
        setPos(x()-5,y());
        if(x() < 30){
            direction = 3;
        }
    }
    if (direction == 3){
        setPos(x()+5,y());
        if(x() > 400){
            direction = 2;
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

void minion_boss::spawn_slime()
{
    if (slime_number < 10){
        vulnerable = false;
        slime* minion = new slime();
        minion->setPos(x()+100,y()+100);
        minion->setScale(0.4);
        scene()->addItem(minion);
        slime_number++;
        connect(minion,SIGNAL(death()),this,SLOT(slime_death()));
    }
}

void minion_boss::slime_death()
{
    slime_number--;
    if(slime_number == 0){
        vulnerable = true;
    }
}

void minion_boss::random_motion_change()
{
    if(horizontal){
        direction = (rand() % 2) + 2;
    }
    if(vertical){
        direction = rand() % 2;
    }
}

void minion_boss::vertical_move()
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


