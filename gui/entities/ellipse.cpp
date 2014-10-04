#include "ellipse.h"

Ellipse::Ellipse(QPointF point1, QPointF point2, QPointF point3)
{
    /* set values of three points
    and calculate radii of ellipse */
    p1 = point1;
    p2 = point2;
    p3 = point3;
    majRadius = qSqrt(qPow((p2.x()-p1.x()), 2) + qPow((p2.y()-p1.y()), 2));
    minRadius = qSqrt(qPow((p3.x()-p1.x()), 2) + qPow((p3.y()-p1.y()), 2));
}

QRectF Ellipse::boundingRect() const
{
    // bounding rectangle for ellipse
    return QRectF(p1.x()-majRadius, p1.y()-minRadius,
                  2*majRadius, 2*minRadius).normalized();
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    // creates the path of ellipse
    QPainterPath ellipse;
    ellipse.moveTo(p1.x()+majRadius, p1.y());
    ellipse.arcTo(boundingRect(), 0 , 360);

    // draws/paints the path of ellipse
    QPen paintpen(Qt::black);
    paintpen.setWidth(1);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(paintpen);
    painter->drawPath(ellipse);
}
