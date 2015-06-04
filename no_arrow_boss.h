#ifndef NO_ARROW_BOSS_H
#define NO_ARROW_BOSS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QSoundEffect>

/** @class no_arrow_boss
 * @brief The no_arrow_boss class is a unique boss that cannot be killed with normal arrows.
 *
 * The no_arrow_boss class publicly derives from the QObject and QGraphicsPixmapItem classes.
 */
class no_arrow_boss: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief no_arrow_boss constructor
     * @param pixmap is a QPixmap object generated from the image file for the no_arrow_boss
     * @param movement is an integer determining the direction of movement
     * @param c is a char determining the direction the no_arrow_boss is firing projectiles
     *
     * movement:\n
     * movement == 0 for initial up direction \n
     * movement == 1 for initial down direction \n
     * movement == 2 for initial left direction \n
     * movement == 3 for initial right direction \n
     * \n
     * c: \n
     * c == 'u' for firing projectiles up \n
     * c == 'd' for firing projectiles down \n
     * c == 'l' for firing projectiles left \n
     * c == 'r' for firing projectiles right \n
     */
    no_arrow_boss(QPixmap pixmap, int movement, char c);
    /**
      * @brief no_arrow_boss destructor
      */
    ~no_arrow_boss();
private:
    int direction;
    bool horizontal;
    bool vertical;
    int fire_direction;
    QSoundEffect* effect;
public slots:
    /**
     * @brief random_motion_change is a custom slot that changes the direction of motion randomly
     */
    void random_motion_change();
    /**
     * @brief vertical_move is a custom slot that controls vertical motion
     */
    void vertical_move();
    /**
     * @brief horizontal_move is a custom slot that controls horizontal motion
     */
    void horizontal_move();
};

#endif // NO_ARROW_BOSS_H
