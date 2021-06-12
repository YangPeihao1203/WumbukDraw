#ifndef TEXT_H
#define TEXT_H

#include <QGraphicsTextItem>
#include "Shape.h"
#define BOLD_SIZE 50
#define DEFAULT_BOLD_SIZE 5
#define TEXT_STEP 20;

class Text:public Shape, public QGraphicsTextItem
{
public:
    Text();
    ~Text()
    {

    }
    //父类的几个通用的方法
    void startDraw(QGraphicsSceneMouseEvent * event);
    void drawing(QGraphicsSceneMouseEvent * event);
    void endDraw(QGraphicsSceneMouseEvent * event);
    bool CheckIsContainsPoint(QPointF);
    void setAdjustFlag(bool);

    //Text特有的，比如双击我应该怎么办，焦点失去的时候我应该怎么办
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);
    void focusOutEvent(QFocusEvent *event) ;

    //通过实践发现，paint是被startDraw、drawing、endDraw这些主动调用的，就是说这个方法是一个被动的方法,
    //即重写了这个paint方法
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;

    void setIsTextBold(bool isTextBold);
    void setTextSize(int textSize);
    void setIsTextItatic(bool isTextItatic);

private:
    bool isTextBold=false;
    int textSize=20;
    bool isTextItatic=false;

};

#endif // TEXT_H
