#ifndef CIRCULAR_H
#define CIRCULAR_H
#include<Shape.h>
#include <QGraphicsEllipseItem>


class Circular : public Shape,public QGraphicsEllipseItem
{
public:
    Circular();
    ~Circular(){

    }
    //表示圆心坐标
    QPointF centerPos;
    void startDraw(QGraphicsSceneMouseEvent * event);
    void drawing(QGraphicsSceneMouseEvent * event);
    void endDraw(QGraphicsSceneMouseEvent * event);
    bool CheckIsContainsPoint(QPointF);
    void setAdjustFlag(bool);
};

#endif // CIRCULAR_H
