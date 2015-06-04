#include "arrow.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "fireball.h"
#include "boss.h"
#include "wall.h"
#include "switch.h"
#include "fire_wall.h"
#include "no_arrow_boss.h"
#include "slime.h"
#include <QSoundEffect>

Arrow::Arrow(int value):direction(value),fire(false),speed(5)
{
  effect = new QSoundEffect();
  effect->setSource(QUrl("qrc:/audio/arrow.wav"));
  effect->setLoopCount(1);
  effect->setVolume(0.25f);
  effect->play();

  if (direction == 0){
      setPixmap(QPixmap(":/images/arrow_up.png"));
  }
  else if (direction == 1){
      setPixmap(QPixmap(":/images/arrow_down.png"));
  }
  else if (direction == 2){
      setPixmap(QPixmap(":/images/arrow_left.png"));
  }
  else if (direction == 3){
     setPixmap(QPixmap(":/images/arrow_right.png"));
  }
  QTimer* timer = new QTimer();
  connect(timer, SIGNAL(timeout()),this, SLOT(move()));
  timer->start(30);
}

Arrow::~Arrow()
{

}

void Arrow::move(){

    QList <QGraphicsItem* > collisions = collidingItems();
    for (auto x: collisions){
        if (typeid(*x) == typeid(fireball)){
            scene()->removeItem(x);
            scene()->removeItem(this);
            delete x;
            delete this;
            return;
        }
        else if (typeid(*x) == typeid(boss)){
            scene()->removeItem(x);
            scene()->removeItem(this);
            delete this;
            delete x;
            return;
        }
        else if (typeid(*x) == typeid(wall)){
            scene()->removeItem(this);
            delete this;
            return;
        }
        else if (typeid(*x) == typeid(Switch)){
            scene()->removeItem(this);
            delete this;
            return;
        }
        else if(typeid(*x) == typeid(fire_wall)){
            if (!fire){
                fire = true;
                if (direction == 0){
                    setPixmap(QPixmap(":/images/fire_arrow_up.png"));
                }
                else if (direction == 1){
                    setPixmap(QPixmap(":/images/fire_arrow_down.png"));
                }
                else if (direction == 2){
                    setPixmap(QPixmap(":/images/fire_arrow_left.png"));
                }
                else if (direction == 3){
                    setPixmap(QPixmap(":/images/fire_arrow_right.png"));
                }
                speed = 10;
                QSoundEffect* feffect = new QSoundEffect();
                feffect->setSource(QUrl("qrc:/audio/fire_arrow.wav"));
                feffect->setLoopCount(1);
                feffect->setVolume(0.25f);
                feffect->play();
            }
        }
        else if(typeid(*x) == typeid(no_arrow_boss)){
            if (fire == true){
                scene()->removeItem(x);
                scene()->removeItem(this);
                delete this;
                delete x;
                return;
            }
        }
        else if (typeid(*x) == typeid(slime)){
            scene()->removeItem(x);
            scene()->removeItem(this);
            delete x;
            delete this;
            return;
        }
    }

    if(direction == 0){
        setPos(x(),y() - speed);
        if (y() < 0){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if (direction == 1){
        setPos(x(),y()+speed);
        if(y() > 530){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if (direction == 2){
        setPos(x() - speed, y());
        if (x() < 0){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if (direction == 3){
        setPos(x() + speed, y());
        if (x() > 530){
            scene()->removeItem(this);
            delete this;
        }
    }
}
