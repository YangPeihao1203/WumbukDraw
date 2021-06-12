#include "staticimage.h"

StaticImage::StaticImage()
{

}
void StaticImage::inSertPicture(QString filePath,QGraphicsScene *parent)
{
                QPixmap pixmap =QPixmap::fromImage(QImage(filePath));
                this->setPixmap(pixmap);
                setFlag(QGraphicsItem::ItemIsMovable);
}



