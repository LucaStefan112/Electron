#ifndef RESISTORSINFO_H
#define RESISTORSINFO_H

#include "UI/UI.h"
#include "Electronic Components/Electronics.h"
#include "Helper.h"

//daria
class ResistorsInfo
{
public:
    ResistorsInfo();

    Button exit;

    Potentiometer_Mobile_Contact potentiometer;
    Resistor_Mobile_Contact_Stop_Position resistorMobileStop;
    Resistor_Mobile_Contact resistorMobile;
    Resistor_Variable_Resistance resistorVariableResistance;
    Resistor resistor;

    int window_code;
    void Show(double w, double h);
    int WatchClick();
    int WatchExit();
};

#endif // RESISTORSINFO_H
