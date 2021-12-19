#ifndef MEASUREMENTSINFO_H
#define MEASUREMENTSINFO_H

#include "UI/InfoScreen.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class MeasurementsInfo: public InfoScreen
{
    public:
        MeasurementsInfo();
        void Show(double w, double h);
};


#endif // MEASUREMENTSINFO_H
