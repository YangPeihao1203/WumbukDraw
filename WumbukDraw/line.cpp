#include "line.h"

Line::Line()
{
setAdjustFlag(false);
}

void Line::startDraw(QGraphicsSceneMouseEvent * event)
{
    QPen pen = this->pen();
    pen.setWidth(this->width);
    pen.setColor(this->color);
    setPen(pen);
    startPos=event->scenePos();
}


void Line::drawing(QGraphicsSceneMouseEvent * event)
{
    EndPos=event->scenePos();
    QLineF newLine(startPos,EndPos);
    setLine(newLine);

}

void Line::endDraw(QGraphicsSceneMouseEvent *event)
{

}

bool Line::CheckIsContainsPoint(QPointF p)
{
    return shape().contains(p);
}
void Line::setAdjustFlag(bool val)
{
   setFlag(QGraphicsItem::ItemIsMovable, val);
   setFlag(QGraphicsItem::ItemIsSelectable, val);
   setFlag(QGraphicsItem::ItemIsFocusable, val);
}
