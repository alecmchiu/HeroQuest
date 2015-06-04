#ifndef SLIME_H
#define SLIME_H

#include <QObject>
#include <QGraphicsPixmapItem>

/** @class slime
 * @brief The slime class is a minion of the minion_boss class.
 *
 * The slime class publicly derives from the QObject and QGraphicsPixmapItem classes.
 */
class slime : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief slime constructor
     */
    slime();
    /**
      * @brief slime destructor
      */
    ~slime();
    /**
     * @brief set_movement is a public member function that sets the private variables of the slime class
     */
    void set_movement();
    /**
     * @brief colliding is a function that checks if the slime object is colliding with any other objects
     * @return a boolean that returns true if the slime is colliding with any objects or false otherwise
     */
    bool colliding();
public slots:
    /**
     * @brief move is a custom public slot that controls the motion of the slime object
     */
    void move();
signals:
    /**
     * @brief death is a custom signal used to notify other objects that the slime has died
     */
    void death();
private:
    double x_speed;
    double y_speed;
};

#endif // SLIME_H
