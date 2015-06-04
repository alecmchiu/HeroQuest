#ifndef BOARD_H
#define BOARD_H

#include "room.h"
#include "player.h"
#include <QGraphicsView>
#include <QObject>

/** @class Board
 * @brief The Board class holds an overall structure of the game and essentially manages the entire game.
 *
 * The Board class publicly derives from QGraphicsView.
 */
class Board :  public QGraphicsView
{
    Q_OBJECT
public:
    /**
     * @brief Board constructor
     * @param parent is the parent QWidget of the Board object
     */
    explicit Board(QWidget *parent = 0);
    /**
      * @brief Board destructor
      */
    ~Board();
    /**
     * @brief PortalWarp is a function that controls traversal between Room objects
     * @param a is the Room being traveled to
     */
    void PortalWarp(Room *a);
signals:
    /**
     * @brief defeat is a custom signal emitted when the player is killed
     */
    void defeat();
    /**
     * @brief win is a custom signal emitted when the player has defeated all the bosses
     */
    void win();
public slots:
    /**
     * @brief game_over is custom slot used to emit the defeat() signal
     */
    void game_over();
    /**
     * @brief boss_kill is a custom slot used to alert the Board of a boss kill
     */
    void boss_kill();
private:
    Room* main_room;
    Room* Room1;
    Room* Room2;
    Room* Room3;
    Player* user;
    int bosses;
};

#endif // BOARD_H
