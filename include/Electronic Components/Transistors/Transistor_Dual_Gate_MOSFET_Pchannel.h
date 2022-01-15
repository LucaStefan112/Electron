#ifndef TRANSISTOR_DUAL_GATE_MOSFET_PCHANNEL_H
#define TRANSISTOR_DUAL_GATE_MOSFET_PCHANNEL_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Transistor_Dual_Gate_MOSFET_Pchannel : public ElectronicComponent
{

public:
    Transistor_Dual_Gate_MOSFET_Pchannel();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_DUAL_GATE_MOSFET_PCHANNEL_H
