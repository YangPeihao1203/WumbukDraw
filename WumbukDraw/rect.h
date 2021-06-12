#ifndef RECT_H
#define RECT_H
#include<Shape.h>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsRectItem>

class Rect: public Shape, public QGraphicsRectItem
{
public:
    Rect();
    ~Rect()
    {
    }
    void startDraw(QGraphicsSceneMouseEvent * event);
    void drawing(QGraphicsSceneMouseEvent * event);
    void endDraw(QGraphicsSceneMouseEvent * event);
    bool CheckIsContainsPoint(QPointF);
    void setAdjustFlag(bool);

private:
    //矩形绘制的开始起点，其实就是矩形的左上角点
    QPointF _startPaintPos;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //得到矩形的形状shape，用来判断某点是否被该矩形所包含
    QPainterPath shape()const;
};

#endif // RECT_H
