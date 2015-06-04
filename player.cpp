#include "player.h"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "arrow.h"
#include <QList>
#include "portal.h"
#include "wall.h"
#include "fireball.h"
#include "fire_wall.h"
#include "boss.h"
#include "no_arrow_boss.h"
#include "minion_boss.h"
#include "slime.h"
#include <QTimer>

Player::Player(QPixmap pixmap):QObject(), QGraphicsPixmapItem(pixmap)
{
    cooldown = false;
    alive = true;
    x=300;
    y=300;

    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setScale(0.1);

    QTimer* cooldown_timer = new QTimer();
    connect(cooldown_timer,SIGNAL(timeout()),this,SLOT(cooldown_reset()));
    cooldown_timer->start(1000);

}

Player::~Player()
{

}

void Player::keyPressEvent(QKeyEvent* event){

    QList<QGraphicsItem* > colliding_items =  collidingItems();
    if (colliding_items.size() > 0){
        for (auto w: colliding_items){
            if (typeid(*w) == typeid(Portal)){
                emit PortalCollision(w);
            }
            else if (typeid(*w) == typeid(fireball) ||
                     typeid(*w) == typeid(wall) ||
                     typeid(*w) == typeid(fire_wall) ||
                     typeid(*w) == typeid(boss) ||
                     typeid(*w) == typeid(no_arrow_boss) ||
                     typeid(*w) == typeid(minion_boss) ||
                     typeid(*w) == typeid(slime)) {
                emit GameOver();
            }
            else if (typeid(*w) == typeid(Switch)){
                emit SwitchCollision(w);
            }
        }
    }

    int step = 20;
    switch(event->key()){
    case Qt::Key_W:
        if(y > 0){
            setPos(x,y-step);
        }
        direction = 0;
        break;
    case Qt::Key_A:
        if (x > 0){
            setPixmap(QPixmap(":/images/link.png"));
            setPos(x-step,y);
        }
        direction = 2;
        break;
    case Qt::Key_S:
        if (y+75 < 600){
            setPos(x,y+step);
        }
        direction = 1;
        break;
    case Qt::Key_D:
        if (x+80 < 600){
            setPixmap(QPixmap(":/images/link_right.png"));
            setPos(x+step,y);
        }
        direction = 3;
        break;
    case Qt::Key_Space:
        if (!cooldown){
            shoot(direction);
            cooldown = true;
        }
        break;
    }
    x=pos().x();
    y=pos().y();
}

void Player::shoot(int value){
    Arrow* arrow = new Arrow(value);
    arrow->setPos(pos().x(), pos().y());
    scene()->addItem(arrow);
}

void Player::cooldown_reset()
{
    cooldown = false;
}


