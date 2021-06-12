#include "Mainpaintscene.h"



/**
 * @brief MainPaintScene::MainPaintScene
 * @param parent
 * 构造函数，清除焦点、设置这个区域的范围
 */
MainPaintScene::MainPaintScene(QWidget *parent):
    QGraphicsScene(parent)
{
    clearFocus();
    this->setBackgroundBrush(Qt::white);
    QRect mainRect(0,0,width(),height());
    setSceneRect(mainRect);//设置场景范围
}

/**
 * @brief MainPaintScene::~MainPaintScene
 * 析构函数
 */
MainPaintScene::~MainPaintScene()
{

}

//无后悔药模式，该模式的实现依靠观察者模式
void  MainPaintScene::NoRegret(){
    this->notify();
}


/**
 * @brief MainPaintScene::keyPressEvent
 * @param event
 * 键盘事件
 */
void MainPaintScene::keyPressEvent(QKeyEvent *event)
{
    //获取当前焦点
    QGraphicsItem *focusItem=this-> focusItem();
    //匹配用户按下的快捷键
    switch (event->key())
    {
    //如果按下的是delete键
    case Qt::Key_Delete:
        if(focusItem !=nullptr)
        {
            //通过迭代器找到之前插入的标记和当前标记相等的标记，并且进行标记删除
            for(QList<Shape*>::iterator itr=_shapeList.begin();
                itr!=_shapeList.end();itr++)
            {
                if((*itr)==_currItem)
                {
                    if(_currItem);
                    delete _currItem;
                    _currItem=nullptr;
                    _shapeList.erase(itr);
                    removeItem((QGraphicsPathItem*)_currItem);
                    break;
                }
            }
        }
        break;
    //如果没有找到匹配的快捷键，就执行父类的键盘事件
    default:
        QGraphicsScene::keyPressEvent(event);
    }
}




void MainPaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //首先判断以下该点击的点是否被之前的插入的痕迹所包含
    foreach (Shape *shape, _shapeList) {
        //如果被包含，就_currItem指向这个标记，同时停止执行
        if(shape->CheckIsContainsPoint(event->scenePos()))
        {
            qDebug("shape->CheckIsContainsPoint(event->scenePos())为true");
            _currItem= shape;
            _currItem->SetAdjustState(true);
            QGraphicsScene::mousePressEvent(event);
            return;
        }
    }
    //如果这个点是新的（即不被包含），就匹配当前画笔的形状，
    //根据画笔形状构造新的对象，将该对象加入到scene中进行显示
    //并且记录到_shapeList中进行记录
    switch(_currShapeCode)
    {
    case Shape::PenPath:
    {
        PenPath *penPath = new PenPath;
        _currItem = penPath;
        _currItem->setWidth(this->_width);
        _currItem->setColor(this->_color);
        addItem(penPath);
        _shapeList.push_back(_currItem);
        break;
    }
    case Shape::Line:
    {
        Line *line = new Line;
        _currItem = line;
        _currItem->setWidth(this->_width);
        _currItem->setColor(this->_color);
        addItem(line);
        _shapeList.push_back(_currItem);
        break;
    }
    case Shape::Rect:
    {
        Rect *rect = new Rect;
        _currItem = rect;
        _currItem->setWidth(this->_width);
        _currItem->setColor(this->_color);
        addItem(rect);
        _shapeList.push_back(_currItem);
        break;
    }
    case Shape::Circular:
    {
        Circular *circular = new Circular;
        _currItem = circular;
        _currItem->setWidth(this->_width);
        _currItem->setColor(this->_color);
        addItem(circular);
        _shapeList.push_back(_currItem);
        break;
    }
    case Shape::Ellipse:
    {
        Ellipses *ellipse = new Ellipses;
        _currItem = ellipse;
        _currItem->setWidth(this->_width);
        _currItem->setColor(this->_color);
        addItem(ellipse);
        _shapeList.push_back(_currItem);
        break;
    }
    case Shape::Text:
    {
        Text *text = new Text;
        text->setIsTextBold(this->_isTextBold);
        text->setTextSize(this->_textSize);
        text->setIsTextItatic(this->_isTextItatic);
        _currItem = text;
        _currItem->setWidth(this->_width);
        _currItem->setColor(this->_color);
        addItem(text);
        _shapeList.push_back(_currItem);
        break;
    }
    }
    //然后执行该新的加入到的对象的绘图方法
    if(_currItem) {
        _currItem->startDraw(event);
    }
    //调用父类QGraphicsScene的mousePressEvent方法
    QGraphicsScene::mousePressEvent(event);
}






void MainPaintScene::notify(){
    qDebug("MainPaintScene::notify()");

    for(Shape* item:this->_shapeList){
        item->SetAdjustState();
    }
}


void MainPaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if(_currItem ) {
        _currItem->drawing(event);
    }
    QGraphicsScene::mouseMoveEvent(event);

}

void MainPaintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{  if(_currItem ) {

        _currItem->endDraw(event);

    }
    QGraphicsScene::mouseReleaseEvent(event);
}


/**
 * @brief MainPaintScene::callback
 * 回滚操作，通过迭代器的方式获取最后一个插入的标记
 * 并且将该标记进行移除
 */
void MainPaintScene::callback()
{
        for(QList<Shape*>::iterator itr=this->_shapeList.begin();
            itr!=this->_shapeList.end();itr++){
            itr++;
            if (itr==this->_shapeList.end()){
                itr--;
                removeItem((QGraphicsPathItem*)(_currItem));
                this->_shapeList.erase(itr);
                break;
            }
            itr--;
        }
}


void MainPaintScene::setColor(QColor color)
{
    this->_color=color;
}

void MainPaintScene::setWidth(int width)
{
    this->_width=width;
}

