#ifndef DIODE_TRANSIENT_VOLTAGE_SUPPRESSION_H
#define DIODE_TRANSIENT_VOLTAGE_SUPPRESSION_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Diode_Transient_Voltage_Suppression : public ElectronicComponent
{

public:
    Diode_Transient_Voltage_Suppression();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // DIODE_TRANSIENT_VOLTAGE_SUPPRESSION_H
