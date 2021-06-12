#ifndef MAINPAINTSCENE_H
#define MAINPAINTSCENE_H

//这个一定不能少，否则在QGraphicsScene的构造方法会没有用的
#include <QtWidgets>

#include<ellipse.h>
#include <QGraphicsScene>
#include<Text.h>
#include<qDebug>
#include<line.h>
#include<circular.h>
#include "rect.h"
#include"penpath.h"
#include "image.h"
#include "observetarget.h"

class MainPaintScene: public QGraphicsScene,public OberveTarget
{
    Q_OBJECT
public:
    //观察者模式中具体被观察者的notify方法
    void notify();


    explicit MainPaintScene(QWidget *parent = 0);
    ~MainPaintScene();
    //回滚撤销操作
    void callback();
    //Shape指针对象，用来表示鼠标点击的最新更新对象
    Shape *_currItem;
    //表示当前的画笔的形状
    Shape::Code _currShapeCode=Shape::None;
    //当前画笔颜色
    QColor _color=Qt::black;
    //当前画笔宽度
    int _width=2;
    //表示该MainPaintScene已经插入的标记集合
    QList<Shape*> _shapeList;
    //set方法
    void setColor(QColor color);
    void setWidth(int width);
    //无后悔药模式
    void NoRegret();
    //字体相关设置，比如字体是否加粗、字体的大小、字体是否倾斜
    bool _isTextBold=false;
    int _textSize=20;
    bool _isTextItatic=false;


private:
    //重写键盘单击事件、鼠标单击事件、鼠标拖拽事件、鼠标松开事件
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


    
public slots:
    /**
     * @brief setCurrentShape，通过参数s设置当前画板的画笔形状
     * @param s
     */
    void setCurrentShape(Shape::Code s)
    {
        if(s!=_currShapeCode){
            _currShapeCode=s;
        }
    }
};

#endif // MAINPAINTSCENE_H
