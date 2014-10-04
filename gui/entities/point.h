#ifndef POINT_H
#define POINT_H

#include <QPainter>
#include <QGraphicsItem>

class Point: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Point();

protected:
    QRectF boundingRect() const;
    virtual void paint(QPainter * painter,
                       const QStyleOptionGraphicsItem * option,
                       QWidget * widget);
};

#endif // POINT_H
