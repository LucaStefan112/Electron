#ifndef SWITCHESINFO_H
#define SWITCHESINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class SwitchesInfo: public Screen
{
    public:
        SwitchesInfo();
        
        Button exit;
        void Show(double w, double h);
        void WatchClick();
};

#endif // SWITCHESINFO_H
