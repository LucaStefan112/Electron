#ifndef DIODESINFO_H
#define DIODESINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

class DiodesInfo
{
public:
    DiodesInfo();

    Button exit;
    Diode_Avalance diodeAvalance;
    Diode_Constant_Current diodeConstantCurrent;
    Diode_Gunn diodeGunn;
    Diode_Junction_PN diodeJunction;
    Diode_Laser diodeLaser;
    Diode_Light_Emitting diodeLightEmitting;
    Diode_Photo diodePhoto;
    Diode_PIN diodePin;
    Diode_Schottky diodeSchottky;
    Diode_Shockley diodeShockley;
    Diode_Transient_Voltage_Suppression diodeVoltage;
    Diode_Tunnel diodeTunnel;
    Diode_Varactor diodeVaractor;
    Diode_Zener diodeZener;

    int window_code;

    void Show(double w, double h);
    int WatchClick();
    int WatchExit();
};

#endif // DIODESINFO_H
