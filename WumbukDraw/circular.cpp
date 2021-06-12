#include "circular.h"

Circular::Circular()
{
setAdjustFlag(false);
}




/**
 * @brief Circular::startDraw，开始绘图记录圆心的坐标和该圆的颜色和宽度
 * @param event
 */
void Circular::startDraw(QGraphicsSceneMouseEvent * event)
{
    centerPos=event->scenePos();
    QPen pen = this->pen();
    pen.setWidth(this->width);
    pen.setColor(this->color);
    setPen(pen);
    _finishDraw=false;
}
/**
 * @brief Circular::drawing圆的绘图逻辑
 * @param event
 */
void Circular::drawing(QGraphicsSceneMouseEvent * event)
{
    if(_finishDraw){
        return;
    }
    QPointF curPos=event->scenePos();
    //根据圆的几何性质，我做出的绘图逻辑
    float radias=sqrt((curPos.x()-centerPos.x())*(curPos.x()-centerPos.x())+(curPos.y()-centerPos.y())*(curPos.y()-centerPos.y()));
    setRect(centerPos.x()-radias,centerPos.y()-radias,2*radias,2*radias);
}

void Circular::endDraw(QGraphicsSceneMouseEvent *event)
{
    _finishDraw=true;
}
bool Circular::CheckIsContainsPoint(QPointF p)
{
    return shape().contains(p);
}
void Circular::setAdjustFlag(bool val)
{
   setFlag(QGraphicsItem::ItemIsMovable, val);
   setFlag(QGraphicsItem::ItemIsSelectable, val);
   setFlag(QGraphicsItem::ItemIsFocusable, val);
}
