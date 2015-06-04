#include "wall.h"
#include <QGraphicsScene>
#include <QTimer>

wall::wall(QPixmap pixmap):QGraphicsPixmapItem(pixmap)
{
    active = true;
}

wall::~wall()
{

}

void wall::deactivate()
{
    if (active){
        this->hide();
        QTimer* timer = new QTimer();
        timer->start(5000);
        connect(timer,SIGNAL(timeout()),this,SLOT(reactivate()));
        active = false;
    }
}

void wall::reactivate()
{
    if(!active){
        this->show();
        active = true;
    }
}

void wall::nullify()
{
    delete this;
}

