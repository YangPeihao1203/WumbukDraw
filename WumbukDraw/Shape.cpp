#include "Shape.h"

Shape::Shape()
{
    _isAdjustState =false;
    this->width=2;
    this->color=Qt::black;
}
void Shape::setWidth(int width){
    this->width=width;
}
void Shape::setColor(QColor color)
{
    this->color=color;
}


//void Shape::attach(Observer * observer){

//}
//void Shape::detach(Observer * observer){

//}





