#ifndef TRANSISTOR_MOSFET_PCHANNEL_H
#define TRANSISTOR_MOSFET_PCHANNEL_H
//Tamas Luca-Stefan
#include "Electronic Components/ElectronicComponent.h"

class Transistor_MOSFET_Pchannel : public ElectronicComponent
{

public:
    Transistor_MOSFET_Pchannel();

    //Updating the position of each connection point:
    void updateConnectionPointsPosition();

    //Drawing the component:
    void Show();
};

#endif // TRANSISTOR_MOSFET_PCHANNEL_H
