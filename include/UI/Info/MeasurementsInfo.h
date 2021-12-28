#ifndef MEASUREMENTSINFO_H
#define MEASUREMENTSINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class MeasurementsInfo: public Screen
{
    public:
        MeasurementsInfo();
        
        Button exit;
        void Show(double w, double h);
        void WatchClick();
};


#endif // MEASUREMENTSINFO_H
