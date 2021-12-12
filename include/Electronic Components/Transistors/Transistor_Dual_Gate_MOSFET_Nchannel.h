#ifndef TRANSISTOR_DUAL_GATE_MOSFET_NCHANNEL_H
#define TRANSISTOR_DUAL_GATE_MOSFET_NCHANNEL_H

#include "Electronic Components/ElectronicComponent.h"

class Transistor_Dual_Gate_MOSFET_Nchannel : public ElectronicComponent{

public:
    Transistor_Dual_Gate_MOSFET_Nchannel();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_DUAL_GATE_MOSFET_NCHANNEL_H
