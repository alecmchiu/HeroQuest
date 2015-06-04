#include "switch.h"
#include <QTimer>

Switch::Switch():QGraphicsPixmapItem(QPixmap(":/images/switch_red.png"))
{
    active = false;
}

Switch::~Switch()
{

}

void Switch::activate(QGraphicsItem *item)
{
    if(item == this){
        if (!active){
            QTimer* timer = new QTimer();
            timer->start(5000);
            active = true;
            setPixmap(QPixmap(":/images/switch_green.png"));
            emit green();
            connect(timer,SIGNAL(timeout()),this,SLOT(deactivate()));
        }
    }
}

void Switch::deactivate()
{
    setPixmap(QPixmap(":/images/switch_red.png"));
    active = false;
}

