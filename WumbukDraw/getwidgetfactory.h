#ifndef GETWIDGETFACTORY_H
#define GETWIDGETFACTORY_H
#include<widget.h>
#include<QtWidgets>
#include <QMainWindow>
/**
 * @brief The GetWidgetFactory class
 * 简单工厂模式，抽象工厂类
 */
class GetWidgetFactory
{
public:
    GetWidgetFactory(){}
    virtual ~GetWidgetFactory(){}
    //抽象方法，获得抽象组件
    virtual QWidget* getWidget(){}
};

#endif // GETWIDGETFACTORY_H
