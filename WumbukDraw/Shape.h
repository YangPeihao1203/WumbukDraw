#ifndef SHAPE_H
#define SHAPE_H


#include <QGraphicsSceneMouseEvent>
#include <QtGui>
#include"observer.h"



class Shape:public Observer
{
public:
    enum Code {
        Line,    //直线
        Rect,    //矩形
        Image,   //图片or gif动态图
        PenPath, //钢笔痕迹
        Text,   //文字
        Circular, //圆形
        Ellipse, //椭圆
        None //没有绘制图元
    };
    Shape();
    virtual ~Shape(){}
    //设置调整的状态
    void SetAdjustState(bool val)
    {
        _isAdjustState=val;
        setAdjustFlag(val);
    }
    void SetAdjustState(){
        setAdjustFlag(!_isAdjustState);
    }
    //设置是否完成绘图，该变量主要在rect和ellipse的绘制过程使用
    bool _finishDraw;
    //当前点击点的左边
    QPointF curPoint;
    //set方法
    void setWidth(int width);
    void setColor(QColor color);

    //以下的虚函数规定了该抽象类被子类继承所必须要实现的接口
    //开始绘图
    virtual void startDraw(QGraphicsSceneMouseEvent * event) = 0;
    //正在绘图
    virtual void drawing(QGraphicsSceneMouseEvent * event) = 0;
    //结束绘图
    virtual void endDraw(QGraphicsSceneMouseEvent * event) = 0;
    //检查点QPointF是否被该标记包含
    virtual bool CheckIsContainsPoint(QPointF)=0;
    //设置该标记的状态
    virtual void setAdjustFlag(bool)=0;



protected:
    //采用桥接模式
    int width=2;
    QColor color=Qt::black;

};


#endif // SHAPE_H
