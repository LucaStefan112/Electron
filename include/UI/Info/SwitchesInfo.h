#ifndef SWITCHESINFO_H
#define SWITCHESINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

//daria
class SwitchesInfo
{
public:
    SwitchesInfo();

    Button exit;
    Switch_Closed switchClosed;
    Switch_SPDT switchSPDT;
    Switch_Open switchOpen;
    Switch_DPST switchDPST;
    Switch_Telegraph switchTelegraph;
    Switch_Thermal_Magnetic_Breaker switchThermal;


    int window_code;
    void Show(double w, double h);
    int WatchClick();
    int WatchExit();
};

#endif // SWITCHESINFO_H
