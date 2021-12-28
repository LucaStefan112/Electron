#ifndef LOGICGATESINFO_H
#define LOGICGATESINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class LogicGatesInfo: public Screen
{
    public:
        LogicGatesInfo();
        
        Button exit;
        void Show(double w, double h);
        void WatchClick();
};

#endif // LOGICGATESINFO_H
