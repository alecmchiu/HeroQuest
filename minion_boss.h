#ifndef MINION_BOSS_H
#define MINION_BOSS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QSoundEffect>

/** @class minion_boss
 * @brief The minion_boss class is a special type of boss that spawns slime objects.
 *
 * The minion_boss class publicly derives from the QObject and QGraphicsPixmapItem classes.
 */
class minion_boss : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief minion_boss constructor
     * @param pixmap is a QPixmap object generated from the image file for the minion_boss
     * @param movement is an integer determining the direction of movement
     * @param c is a char determining the direction the minion_boss is firing projectiles
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
    minion_boss(QPixmap pixmap, int movement, char c);
    /**
      * @brief minion_boss destructor
      */
    ~minion_boss();
private:
    int direction;
    bool horizontal;
    bool vertical;
    int fire_direction;
    bool vulnerable;
    int slime_number;
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
    /**
     * @brief spawn_slime is a custom public slot that spawns a slime for the minion_boss
     */
    void spawn_slime();
    /**
     * @brief slime_death is a custom public slot that notifies the minion_boss object when one of its spawned slime objects has died
     */
    void slime_death();
};

#endif // MINION_BOSS_H
