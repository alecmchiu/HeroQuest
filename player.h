#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

/** @class Player
 * @brief The Player class is the object that the player controls.
 *
 * The Player class publicly derives from the QObject and QGraphicsPixmapItem classes.
 */
class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief Player constructor
     * @param pixmap is the QPixmap object that contains the image for the Player object
     */
    Player(QPixmap pixmap);
    /**
      * @brief Player destructor
      */
    ~Player();
    /**
     * @brief keyPressEvent is a public function that controls key presses by the user
     * @param event is the key pressed
     *
     * event: \n
     * event == W key for up motion \n
     * event == A key for left motion \n
     * event == S for down motion \n
     * event == D for right motion \n
     * event == spacebar to shoot an Arrow object \n
     */
    void keyPressEvent(QKeyEvent* event);
    double x;
    double y;

public slots:
    /**
     * @brief shoot is a custom public slot that generates an Arrow projectile
     * @param value is the direction it is being shot
     *
     * value: \n
     * value == 0 for up motion \n
     * value == 1 for down motion \n
     * value == 2 for left motion \n
     * value == 3 for right motion \n
     */
    void shoot(int value);
    /**
     * @brief cooldown_reset is a custom public slot that is used to reset the shooting cooldown
     */
    void cooldown_reset();

signals:
    /**
     * @brief PortalCollision is a custom signal used to traverse Room objects through Portal objects
     * @param port is the Portal object being used to traverse
     */
    void PortalCollision(QGraphicsItem* port);
    /**
     * @brief GameOver is a custom signal used to alert other objects when the user has died
     */
    void GameOver();
    /**
     * @brief SwitchCollision is a custom signal used to detect whether the player is interacting with a Switch object
     * @param item is the Switch object being collided with
     */
    void SwitchCollision(QGraphicsItem* item);
private:
    bool alive;
    int direction;
    bool cooldown;
};

#endif // PLAYER_H
