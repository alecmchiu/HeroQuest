#include "fire_wall.h"
#include <QTimer>

fire_wall::fire_wall():QGraphicsPixmapItem(QPixmap(":/images/fire_wall.png"))
{
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(3000);

}

fire_wall::~fire_wall()
{

}

void fire_wall::move()
{
    double new_y = rand () % 500;
    setPos(x(),new_y);
}

