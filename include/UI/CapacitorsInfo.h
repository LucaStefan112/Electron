#ifndef CAPACITORSINFO_H
#define CAPACITORSINFO_H

#include "UI/InfoScreen.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class CapacitorsInfo: public InfoScreen
{
    public:
        CapacitorsInfo();
        void Show(double w, double h);
};

#endif // CAPACITORSINFO_H
