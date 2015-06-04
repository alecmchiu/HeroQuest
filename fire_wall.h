#ifndef FIRE_WALL_H
#define FIRE_WALL_H

#include <QObject>
#include <QGraphicsPixmapItem>

/** @class fire_wall
 * @brief The fire_wall class is interacts with the Arrow class. It is designed as a mechanic for the no_arrow_boss class.
 */
class fire_wall : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief fire_wall constructor
     */
    fire_wall();
    /**
      * @brief fire_wall destructor
      */
    ~fire_wall();
public slots:
    /**
     * @brief move is a custom slot that controls the random motion of the fire_wall object
     */
    void move();
};

#endif // FIRE_WALL_H
