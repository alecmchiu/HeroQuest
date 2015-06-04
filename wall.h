#ifndef WALL_H
#define WALL_H

#include <QObject>
#include <QGraphicsPixmapItem>

/** @class wall
 * @brief The wall class is a class that is used as a boss mechanic.
 *
 * The wall class publicly derives from the QObject and QGraphicsPixmapItem classes.
 */
class wall : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief wall constructor
     * @param pixmap is a QPixmap object that contains the image for the wall object
     */
    wall(QPixmap pixmap);
    /**
      * @brief wall destructor
      */
    ~wall();
public slots:
    /**
     * @brief deactivate is a public slot that deactivates the wall object
     */
    void deactivate();
    /**
     * @brief reactivate is a public slot that reactives the wall
     */
    void reactivate();
    /**
     * @brief nullify is a public slot that permanently deactivates the wall
     */
    void nullify();
private:
    bool active;
};

#endif // WALL_H
