#ifndef ROOM_H
#define ROOM_H

#include <QGraphicsScene>
#include <QPixmap>
#include <QObject>

/** @class Room
 * @brief The Room class controls each of the zones in the game.
 *
 * The Room class publicly derives from the QGraphicsScene class.
 */
class Room : public QGraphicsScene
{
    Q_OBJECT
public:
    /**
      * @brief Room constructor
      * @param a is a QPixmap object that contains the tileset images for the Room
      */
     Room(QPixmap a);
     /**
      *
      */
    ~Room();

protected:
    QPixmap* tile;
};

#endif // ROOM_H
