#ifndef TRANSISTOR_INDUCTIVE_CHANNEL_MOSFET_PCHANNEL_H
#define TRANSISTOR_INDUCTIVE_CHANNEL_MOSFET_PCHANNEL_H

#include "Electronic Components/ElectronicComponent.h"

class Transistor_Inductive_Channel_MOSFET_Pchannel : public ElectronicComponent{

public:
    Transistor_Inductive_Channel_MOSFET_Pchannel();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_INDUCTIVE_CHANNEL_MOSFET_PCHANNEL_H
