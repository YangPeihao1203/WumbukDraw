#include "image.h"

Image::Image()
{
    setAdjustFlag(false);
}
//因为图片只要插入，所以startDraw、drawing、endDraw为空实现
void Image::startDraw(QGraphicsSceneMouseEvent * event)
{

}
void Image::drawing(QGraphicsSceneMouseEvent * event)
{

}
void Image::endDraw(QGraphicsSceneMouseEvent *event)
{

}
bool Image::CheckIsContainsPoint(QPointF p)
{
    return contains(p);
}
//设置该标记是否可以移动、可以被选中、可以获取焦点
void Image::setAdjustFlag(bool val)
{
   setFlag(QGraphicsItem::ItemIsMovable, val);
   setFlag(QGraphicsItem::ItemIsSelectable, val);
   setFlag(QGraphicsItem::ItemIsFocusable, val);
}

