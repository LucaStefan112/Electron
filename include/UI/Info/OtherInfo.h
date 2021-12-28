#ifndef OTHERINFO_H
#define OTHERINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class OtherInfo: public Screen
{
    public:
        OtherInfo();
        
        Button exit;
        void Show(double w, double h);
        void WatchClick();
};

#endif // OTHERINFO_H
