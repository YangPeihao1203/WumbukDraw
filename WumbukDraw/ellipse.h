#ifndef ELLIPSE_H
#define ELLIPSE_H
#include<Shape.h>
#include <QGraphicsEllipseItem>

class  Ellipses: public Shape,public QGraphicsEllipseItem
{
public:
    Ellipses();
    ~Ellipses(){
    }
    //椭圆中心点坐标
    QPointF centerPos;
    void startDraw(QGraphicsSceneMouseEvent * event);
    void drawing(QGraphicsSceneMouseEvent * event);
    void endDraw(QGraphicsSceneMouseEvent * event);
    bool CheckIsContainsPoint(QPointF);
    void setAdjustFlag(bool);
};

#endif // ELLIPSE_H
