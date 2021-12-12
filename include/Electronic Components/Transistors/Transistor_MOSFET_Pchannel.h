#ifndef TRANSISTOR_MOSFET_PCHANNEL_H
#define TRANSISTOR_MOSFET_PCHANNEL_H

#include "ElectronicComponent.h"

class Transistor_MOSFET_Pchannel : public ElectronicComponent{

public:
    Transistor_MOSFET_Pchannel();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_MOSFET_PCHANNEL_H
