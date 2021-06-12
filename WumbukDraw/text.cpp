#include "Text.h"

//构造函数，设置字体的大小，设置加粗，字体相关属性等
Text::Text()
{
    QFont f;
    f.setPointSize(50);
    f.setBold(true);
    f.setFamily("Helvetica");
    setFont(f);
    //文字可编辑状态
    setTextInteractionFlags(Qt::TextEditorInteraction);
    setZValue(1000.0);
}
//重写焦点失去函数，文字设置不可交互
void Text::focusOutEvent(QFocusEvent *event)
{
    setTextInteractionFlags(Qt::NoTextInteraction);
    QGraphicsTextItem::focusOutEvent(event);
}
//重写鼠标双击函数，文字设置可交互
void Text::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event)
{
    if (textInteractionFlags() == Qt::NoTextInteraction)
        setTextInteractionFlags(Qt::TextEditorInteraction);
    QGraphicsTextItem::mouseDoubleClickEvent(event);
}

//开始绘制文字函数，设置文字颜色、字体等属性，确定文字的位置
void Text::startDraw(QGraphicsSceneMouseEvent * event)
{
    setDefaultTextColor(this->color);
    QFont font =this->font();
    font.setPixelSize(this->textSize);
    font.setItalic(this->isTextItatic);
    font.setBold(this->isTextBold);
    setFont(font);
    setPos(event->scenePos());
}
//空实现
void Text::drawing(QGraphicsSceneMouseEvent * event)
{
}
//空实现
void Text::endDraw(QGraphicsSceneMouseEvent *event)
{
}
//检查该点是否被文字所包含
bool Text::CheckIsContainsPoint(QPointF p)
{
    return shape().contains(p);
}
//设置文字状态
void Text::setAdjustFlag(bool val)
{
    setFlag(QGraphicsItem::ItemIsMovable, val);
    setFlag(QGraphicsItem::ItemIsSelectable, val);
    setFlag(QGraphicsItem::ItemIsFocusable, val);
}

void Text::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //使用父方法
    QGraphicsTextItem::paint(painter,option,widget);
}









void Text::setIsTextBold(bool isTextBold)
{
   this->isTextBold=isTextBold;
}
void Text::setTextSize(int textSize)
{
   this->textSize=textSize;
}

void Text::setIsTextItatic(bool isTextItatic)
{
    this->isTextItatic=isTextItatic;
}

