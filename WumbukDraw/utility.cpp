#include "utility.h"

Utility::Utility()
{
}

//将该文件存储为Png,jpg等格式
void Utility::saveFile(QString filePath, MainPaintScene* mMainPaintScene)
{
        QSize mysize(mMainPaintScene->width(),mMainPaintScene->height());
        QImage image(mysize,QImage::Format_RGB32);
        QPainter painter(&image);
        mMainPaintScene->render(&painter);
        image.save(filePath);
}

//未实现
void Utility::saveFileToEdit(QString filePath, MainPaintScene *mMainPaintScene)
{
    //TODO
        //思路是 循环遍历mMainPaintScene中每个item的x,y,width,height的值，并且存储到本地文件上
}

//未实现
MainPaintScene* Utility::readFile(QString filePath)
{
    MainPaintScene *mMainPaintScene=new MainPaintScene;

    //TODO
    //思路是先新建一个MainPaintScene对象，然后通过读文件的内容对该对象添加item，并且同时更新该对象的vector

    //返回该对象。
    return mMainPaintScene;
}

QString Utility::cssFromColor(QColor color)
{
    if(color.isValid()==false)
        return nullptr;
    int r,g,b;
    color.getRgb(&r,&g,&b);
    return QString("background-color: rgb(%1, %2, %3);").arg(r).arg(g).arg(b);
}







