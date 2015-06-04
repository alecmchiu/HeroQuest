#ifndef ARROW_H
#define ARROW_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "switch.h"
#include <QSoundEffect>

/**
  @class Arrow
  @brief The Arrow class represents the projectiles the player uses.

  The Arrow class publicly derives from the QObject and QGraphicsPixmapItem classes.

*/

class Arrow : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief Arrow constructor
     * @param value is an integer that determines the direction the arrow is fired
     *
     * value == 0 for up motion \n
     * value == 1 for down motion \n
     * value == 2 for left motion \n
     * value == 3 for right motion \n
     */
    Arrow(int value);
    /**
      * @brief Arrow deconstructor
      */
    ~Arrow();
public slots:
    /**
     * @brief move is a function that controls motion of the player
     */
    void move();
private:
    int direction;
    bool fire;
    int speed;
    QSoundEffect* effect;
};

#endif // ARROW_H
