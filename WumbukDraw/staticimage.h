#ifndef STATICIMAGE_H
#define STATICIMAGE_H
#include "image.h"
#include <QGraphicsPixmapItem>
class StaticImage:public Image
{
public:
    StaticImage();
    void inSertPicture(QString filePath,QGraphicsScene *parent);
};

#endif // STATICIMAGE_H
