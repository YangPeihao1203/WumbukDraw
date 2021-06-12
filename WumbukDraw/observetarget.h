#ifndef OBSERVETARGET_H
#define OBSERVETARGET_H

#include "observer.h"



class OberveTarget
{
public:
    OberveTarget(){}
    virtual ~OberveTarget(){}
protected:
    QList<Observer*> _shapeList;
public:
    void attach(Observer * observer){
        this->_shapeList.push_back(observer);
    };

    void detach(Observer * observer){
        for(QList<Observer*>::iterator itr=_shapeList.begin();
            itr!=_shapeList.end();itr++)
        {
            if((*itr)==observer)
            {
                if(observer);
                delete observer;
                _shapeList.erase(itr);
                break;
            }
        }
    }
    //通知方法，通过该方法通知观察该目标的观察者们
    virtual void notify(){};
};

#endif // OBSERVETARGET_H
