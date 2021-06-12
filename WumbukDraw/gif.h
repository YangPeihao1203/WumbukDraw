#ifndef GIF_H
#define GIF_H


#include <QLabel>
#include <QGraphicsProxyWidget>
#include"image.h"
class Gif: public Image
{
public:
    Gif();
    void inSertPicture(QString filePath,QGraphicsScene *parent);
};


#endif // GIF_H
