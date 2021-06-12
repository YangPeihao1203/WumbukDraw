#ifndef IMAGE_H
#define IMAGE_H


#include "Shape.h"
#include <QGraphicsScene>
#include"QGraphicsPixmapItem"
class Image: public Shape,public QGraphicsPixmapItem
{
public:
    Image();
    ~Image()
    {

    }
    //实现父类的虚函数
    void startDraw(QGraphicsSceneMouseEvent * event);
    void drawing(QGraphicsSceneMouseEvent * event);
    void endDraw(QGraphicsSceneMouseEvent * event);
    bool CheckIsContainsPoint(QPointF);
    void setAdjustFlag(bool);
    //自己将Image通过该虚函数设定为抽象类，插入图片
    virtual void inSertPicture(QString filePath,QGraphicsScene *parent)=0;
};

#endif // IMAGE_H
