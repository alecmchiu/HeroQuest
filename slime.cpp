#include "slime.h"
#include <QList>
#include <QTimer>

slime::slime():QGraphicsPixmapItem(QPixmap(":/images/slime_right.png")),x_speed(5),y_speed(5)
{
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(500);
}

slime::~slime()
{
    emit death();
}

void slime::set_movement()
{
    x_speed = rand()%5;
    y_speed = rand()%10;

    if(rand()%2 == 0){
        x_speed = -x_speed;
    }
    if (rand()%2 == 0) {
        y_speed = -y_speed;
    }
}

bool slime::colliding()
{
    QList<QGraphicsItem*> list = collidingItems();
    if (list.size() > 0){
        return true;
    }
    else return false;
}

void slime::move()
{
    if (colliding()){
        set_movement();
    }

    setPos(x()+x_speed,y()+y_speed);
    if (x() < 0) {
        x_speed = -x_speed;
    }
    else if (x() > 570){
        x_speed = -x_speed;
    }
    if (y() < 10){
        y_speed = -y_speed;
    }
    else if (y() > 580){
        y_speed = -y_speed;
    }
}

