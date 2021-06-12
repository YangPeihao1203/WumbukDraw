#ifndef GETMAINPAINTSCENEFACTORY_H
#define GETMAINPAINTSCENEFACTORY_H
#include"getwidgetfactory.h"
#include"mainpaintscene.h"

class GetMainPaintSceneFactory:public GetWidgetFactory
{
public:
    GetMainPaintSceneFactory();
    QWidget* getWidget();
};

#endif // GETMAINPAINTSCENEFACTORY_H
