#ifndef OBSERVER_H
#define OBSERVER_H


class Observer
{
public:
    Observer();
    virtual ~Observer(){};
    virtual void SetAdjustState()=0;


protected:
    bool _isAdjustState;
};

#endif // OBSERVER_H
