#include "ellipse.h"


Ellipses::Ellipses()
{
setAdjustFlag(false);
}





void Ellipses::startDraw(QGraphicsSceneMouseEvent * event)
{
    centerPos=event->scenePos();
    _finishDraw=false;
    QPen pen = this->pen();
    pen.setWidth(this->width);
    pen.setColor(this->color);
    setPen(pen);

}

void Ellipses::drawing(QGraphicsSceneMouseEvent * event)
{
    if(_finishDraw){
        return;
    }
    QPointF curPos=event->scenePos();
    qreal distanceX=abs(curPos.x()-centerPos.x());
    qreal distanceY=abs(curPos.y()-centerPos.y());
    setRect(centerPos.x()-distanceX,centerPos.y()-distanceY,2*distanceX,2*distanceY);
}

void Ellipses::endDraw(QGraphicsSceneMouseEvent *event)
{
    _finishDraw=true;

}
bool Ellipses::CheckIsContainsPoint(QPointF p)
{
    return shape().contains(p);
}
void Ellipses::setAdjustFlag(bool val)
{
   setFlag(QGraphicsItem::ItemIsMovable, val);
   setFlag(QGraphicsItem::ItemIsSelectable, val);
   setFlag(QGraphicsItem::ItemIsFocusable, val);
}


