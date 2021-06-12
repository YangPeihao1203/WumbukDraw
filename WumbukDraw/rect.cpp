#include "rect.h"

/**
 * @brief Rect::Rect，构造函数，设置该矩形在z坐标值，该矩形是否允许被拖拽，该矩形是否允许被调整大小
 */
Rect::Rect()
{
    setZValue(0);
    setAcceptDrops(true);
    setAdjustFlag(false);
}
/**
 * @brief Rect::startDraw，开始画矩形
 * @param event
 */
void Rect::startDraw(QGraphicsSceneMouseEvent * event)
{
    //矩形的左上角坐标
    _startPaintPos=event->scenePos();
    //一旦开始按下鼠标左键_finishDraw=false，表示该图形正在绘制，还没有绘制完成
    _finishDraw=false;
    //设置该画笔的颜色和宽度
    QPen pen = this->pen();
    pen.setWidth(this->width);
    pen.setColor(this->color);
    setPen(pen);
}
void Rect::drawing(QGraphicsSceneMouseEvent * event)
{
    //如果完成了画图，就返回
    if(_finishDraw)
        return;
    //以下为矩形的绘制逻辑
    QPointF pos =event->scenePos();
    QPointF dis =pos-_startPaintPos;
    if(pos.rx() > _startPaintPos.rx() && pos.ry() >_startPaintPos.ry())
        setRect(_startPaintPos.rx(),_startPaintPos.ry(),dis.rx(),dis.ry());
    else if(pos.rx() > _startPaintPos.rx() && pos.ry() <_startPaintPos.ry())
        setRect(_startPaintPos.rx(),pos.ry(),dis.rx(),-dis.ry());
    else if(pos.rx() < _startPaintPos.rx() && pos.ry() >_startPaintPos.ry())
        setRect(pos.rx(),_startPaintPos.ry(),-dis.rx(),dis.ry());
    else if(pos.rx() < _startPaintPos.rx() && pos.ry() <_startPaintPos.ry())
        setRect(pos.rx(),pos.ry(),-dis.rx(),-dis.ry());
}

void Rect::endDraw(QGraphicsSceneMouseEvent *event)
{
    _finishDraw=true;
    //绘制结束进入编辑状态
}
bool Rect::CheckIsContainsPoint(QPointF pointf)
{
    return shape().contains(mapFromScene(pointf));
}
//重写shape方法
QPainterPath Rect::shape()const{
    QPainterPath path;
    path.addRect(rect());
    return path;
}




void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
QGraphicsRectItem::paint(painter,option,widget);
}




void Rect::setAdjustFlag(bool val)
{
    setFlag(QGraphicsItem::ItemIsMovable, val);
    setFlag(QGraphicsItem::ItemIsSelectable, val);
    setFlag(QGraphicsItem::ItemIsFocusable, val);
}





