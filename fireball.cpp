#include "fireball.h"
#include <QTimer>
#include <QGraphicsScene>

fireball::fireball(int value)
{
    direction = value;
    if (direction == 0){
        setPixmap(QPixmap(":/images/fireball_up.png"));
    }
    else if (direction == 1){
        setPixmap(QPixmap(":/images/fireball_down.png"));
    }
    else if (direction == 2){
        setPixmap(QPixmap(":/images/fireball_left.png"));
    }
    else if (direction == 3){
       setPixmap(QPixmap(":/images/fireball_right.png"));
    }
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(30);
}

fireball::~fireball()
{

}

void fireball::move()
{
    if(direction == 0){
        setPos(x(),y() - 5);
        if (y() < 0){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if (direction == 1){
        setPos(x(),y()+5);
        if(y() > 530){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if (direction == 2){
        setPos(x() - 5, y());
        if (x() < 0){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if (direction == 3){
        setPos(x() + 5, y());
        if (x() > 530){
            scene()->removeItem(this);
            delete this;
        }
    }
}

