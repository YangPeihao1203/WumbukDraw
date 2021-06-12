#include "penpath.h"

/**
 * @brief PenPath::PenPath
 * 设置标记默认不可移动
 */
PenPath::PenPath()
{
    //设置该标记可以移动、该标记可以被选择
    setFlag(QGraphicsItem::ItemIsMovable, false);
    setFlag(QGraphicsItem::ItemIsSelectable, false);
}

void PenPath::startDraw(QGraphicsSceneMouseEvent * event)
{
    
    curPoint =event->scenePos();

    //开始自由绘图
    QPen pen = this->pen();
    pen.setWidth(this->width);
    pen.setColor(this->color);
    setPen(pen);
    _path.moveTo(curPoint);
}

void PenPath::drawing(QGraphicsSceneMouseEvent * event)
{

    _path.lineTo(event->scenePos());
     setPath(_path);
}





void PenPath::endDraw(QGraphicsSceneMouseEvent *event)
{
}
//检测某一个点是否被路径所包含
bool PenPath::CheckIsContainsPoint(QPointF pointf)
{
   return  path().contains(pointf);
}

void PenPath::setAdjustFlag(bool val)
{
   setFlag(QGraphicsItem::ItemIsMovable, val);
   setFlag(QGraphicsItem::ItemIsSelectable, val);
   setFlag(QGraphicsItem::ItemIsFocusable, val);
}


