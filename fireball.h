#ifndef FIREBALL_H
#define FIREBALL_H

#include <QObject>
#include <QGraphicsPixmapItem>

/** @class fireball
 * @brief The fireball class represents the projectiles for enemies such as bosses.
 */
class fireball : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief fireball constructor
     * @param value controls the direction of the fireball's motion
     *
     * value:
     * value == 0 for up motion \n
     * value == 1 for down motion \n
     * value == 2 for left motion \n
     * value == 3 for right motion \n
     */
    fireball(int value);
    /**
      * @brief fireball destructor
      */
    ~fireball();
private:
    int direction;
public slots:
    /**
     * @brief move is a custom slot that controls the motion of the fireball
     */
    void move();
};

#endif // FIREBALL_H
