#ifndef PORTAL_H
#define PORTAL_H

#include <QGraphicsPixmapItem>
#include "room.h"
#include <QObject>
#include "board.h"

/** @class Portal
 * @brief The Portal class is a class used to traverse between Room objects
 *
 * The Portal class publicly derives from the QObject and QGraphicsPixmapItem classes.
 */
class Portal : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief Portal constructor
     * @param to is the Room object it starts from
     * @param board is the Board object containg the Portal
     */
    Portal(Room* to, Board* board);
    /**
      * @brief Portal destructor
      */
    ~Portal();
    Room* to;
    Board* board;
public slots:
    /**
     * @brief Collided is a custom public slot that detects whether the Player is interacting with it
     * @param port is the Portal object being interacted with
     */
    void Collided(QGraphicsItem* port);
};

#endif // PORTAL_H
