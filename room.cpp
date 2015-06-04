#include "room.h"

Room::Room(QPixmap a) : QGraphicsScene()
{
    tile = new QPixmap(a);
    QBrush tile_background(*tile);
    setBackgroundBrush(tile_background);
    setSceneRect(0,0,600,600);
}

Room::~Room()
{

}

