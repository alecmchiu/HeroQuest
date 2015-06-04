#include "portal.h"
#include "board.h"

Portal::Portal(Room *to, Board *board):QGraphicsPixmapItem(QPixmap(":/images/portal.png"))
{
    this->to = to;
    this->board = board;
    setScale(0.25);
}

Portal::~Portal()
{

}

void Portal::Collided(QGraphicsItem* port)
{
    if (port == this){
        board->PortalWarp(to);
    }
}
