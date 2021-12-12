#ifndef TRANSISTOR_DUAL_GATE_MOSFET_PCHANNEL_H
#define TRANSISTOR_DUAL_GATE_MOSFET_PCHANNEL_H

#include "Electronic Components/ElectronicComponent.h"

class Transistor_Dual_Gate_MOSFET_Pchannel : public ElectronicComponent{

public:
    Transistor_Dual_Gate_MOSFET_Pchannel();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_DUAL_GATE_MOSFET_PCHANNEL_H
