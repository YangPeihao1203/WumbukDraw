#include "gif.h"


Gif::Gif()
{

}

/**
 * @brief Gif::inSertPicture，将filePath文件插入到父组件parent中
 * @param filePath
 * @param parent
 */
void Gif::inSertPicture(QString filePath,QGraphicsScene *parent)
{
        QLabel *gif_anim=new QLabel();
        QMovie *movie=new QMovie(filePath);
        gif_anim->setMovie(movie);
        movie->start();
        QGraphicsProxyWidget* item=parent->addWidget(gif_anim);
        //设置gif组件的父组件容器
        QGraphicsWidget* parentWidget = new QGraphicsWidget();
        parentWidget->setMinimumSize(QSizeF(item->widget()->width(), item->widget()->height()));
        parentWidget->setFlags(QGraphicsItem::ItemIsMovable);
        //默认灰色，不设置则为背景色
        parentWidget->setAutoFillBackground(true);
        //父组件和子组件的互相指定
        parent->addItem(parentWidget);
        item->setParentItem(parentWidget);
}
