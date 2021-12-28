#ifndef TRANSISTORSINFO_H
#define TRANSISTORSINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class TransistorsInfo: public Screen
{
    public:
        TransistorsInfo();
        
        Button exit;
        void Show(double w, double h);
        void WatchClick();
};

#endif // TRANSISTORSINFO_H
