#include "getLableFactory.h"
GetMainPaintSceneFactory::GetMainPaintSceneFactory()
{
}

QWidget* GetMainPaintSceneFactory::getWidget(){
    return new QLabel;
}
