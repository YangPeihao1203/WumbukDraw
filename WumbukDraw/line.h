#ifndef LINE_H
#define LINE_H

#include <QGraphicsLineItem>
#include "Shape.h"

class Line : public Shape, public QGraphicsLineItem
{
public:
    Line();
    ~Line()
    {
    }
    //直线开始的点
    QPointF startPos;
    //直线结束的点
    QPointF EndPos;
    void startDraw(QGraphicsSceneMouseEvent * event);
    void drawing(QGraphicsSceneMouseEvent * event);
    void endDraw(QGraphicsSceneMouseEvent * event);
    bool CheckIsContainsPoint(QPointF);
    void setAdjustFlag(bool);
};

#endif // LINE_H
