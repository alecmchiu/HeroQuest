#ifndef SWITCH_H
#define SWITCH_H

#include <QObject>
#include <QGraphicsPixmapItem>

/** @class Switch
 * @brief The Switch class is a class that has an on and off state and is used as a boss mechanic.
 *
 * The Switch class publicly derives from the QObject and QGraphicsPixmapItem classes.
 */
class Switch : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief Switch constructor
     */
    Switch();
    /**
      * @brief Switch destructor
      */
    ~Switch();
signals:
    /**
     * @brief green is a custom signal that notifies other objects if it is active
     */
    void green();
public slots:
    /**
     * @brief activate is a custom public slot that activates the Switch object
     * @param item is the Switch object being activated
     */
    void activate(QGraphicsItem* item);
    /**
     * @brief deactivate is a custom public slot that deactivates the Switch object
     */
    void deactivate();
private:
    bool active;
};

#endif // SWITCH_H
