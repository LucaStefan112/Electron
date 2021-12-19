#ifndef TRANSISTORSINFO_H
#define TRANSISTORSINFO_H

#include "UI/InfoScreen.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class TransistorsInfo: public InfoScreen
{
    public:
        TransistorsInfo();
        void Show(double w, double h);
};

#endif // TRANSISTORSINFO_H
