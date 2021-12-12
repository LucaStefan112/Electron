#ifndef DIODE_TRANSIENT_VOLTAGE_SUPPRESSION_H
#define DIODE_TRANSIENT_VOLTAGE_SUPPRESSION_H

#include "ElectronicComponent.h"

class Diode_Transient_Voltage_Suppression : public ElectronicComponent{

public:
    Diode_Transient_Voltage_Suppression();

    //Drawing the component:
    void Show();
};

#endif // DIODE_TRANSIENT_VOLTAGE_SUPPRESSION_H
