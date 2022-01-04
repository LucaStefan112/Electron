#ifndef CAPACITORSINFO_H
#define CAPACITORSINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"
#include "Enums.h"

class CapacitorsInfo
{
    public:
        CapacitorsInfo();

        Button exit;
        Capacitor_Ceramic capacitorCeramic;
        Capacitor_Electrolytic capacitorElectrolyt;
        Capacitor_Trimmer capacitorTrimmer;
        Capacitor_Variable capacitorVariable;

        int window_code;

        void Show(double w, double h);
        int WatchClick();
        int WatchExit();
};

#endif // CAPACITORSINFO_H
